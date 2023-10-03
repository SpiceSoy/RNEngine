// ================================================================================================
//   @file GlobalMacro.h
//  
//   @brief 
//   
//   @date 2023/09/30
// ================================================================================================

#pragma once

#include "Platform/Core/PlatformDefine.h"
#include <string_view>


// 타입 관련
namespace Rn
{
	class IRnType;
	using FClassID = void*;
	using FClassName = std::string_view;


	namespace Concept
	{
		template < typename Ty >
		concept HasClassID = std::is_same_v< decltype( std::declval< Ty >().GetID() ), FClassID >;
	}


	template < typename Ty >
	class TClassID
	{
	private:
		using ThisType = TClassID< Ty >;
		inline static const Ty* _classAddress = nullptr;

	public:
		static FClassID GetID()
		{
			return &_classAddress;
		}

		template < typename Ty2 > requires Concept::HasClassID< Ty >
		bool operator==( Ty2 InOtherID )
		{
			return GetID() == Ty2::GetID();
		}
	};


	template < typename Ty >
	class TClassName
	{
	private:
		using ThisType = TClassName< Ty >;
		static FClassName _className;

	public:
		static FClassName GetName()
		{
			return _className;
		}
	};


	class IRnType
	{
	public:
		IRnType() = default;

		virtual ~IRnType() = default;
	};


	class IRnObject : public IRnType
	{
	public:
		IRnObject() = default;

		virtual ~IRnObject() override = default;

		virtual FClassID GetClassID() const = 0;

		virtual FClassName GetName() const = 0;
	};


	namespace Concept
	{
		template < typename Ty >
		concept IsRnType = std::is_base_of_v< IRnType, Ty > == true;

		template < typename Ty >
		concept IsRnObject = std::is_base_of_v< IRnObject, Ty > == true;
	}
}


#define DECLARE_RN_TYPE( TYPE ) \
	private:\
		using ThisType = TYPE;\
		static const TClassID< TYPE > _classID;\
	public:\
		static FClassID StaticClassID() { return TClassID<TYPE>::GetID(); };

#define DECLARE_RN_OBJECT( TYPE ) \
	private:\
		using ThisType = TYPE;\
		static const TClassID< TYPE > _classID;\
		static const TClassName< TYPE > _className;\
	public:\
		virtual FClassID GetClassID() const override { return _classID.GetID(); }\
		virtual FClassName GetName() const override { return _className.GetName(); }

#define IMPLEMENT_RN_OBJECT( TYPE ) \
	Rn::FClassName Rn::TClassName< TYPE >::_className = #TYPE;


// 콘셉트
namespace Rn::Concept
{
	template < typename Ty >
	concept IsArithmetic = std::is_arithmetic_v< Ty > == true;

	template < typename Ty >
	concept IsIDType = std::is_integral_v< Ty > == true;

	template < typename... CheckTy >
	concept IsNotVoid = std::is_void_v< CheckTy... > != true;

	template < typename... CheckTys >
	concept IsNotVoids = ( IsNotVoid< CheckTys > && ... );

	template < typename... CheckTy >
	concept IsVoid = std::is_void_v< CheckTy... > == true;

	template < typename... CheckTys >
	concept IsVoids = ( IsVoid< CheckTys > && ... );

	template < typename Ty1, typename Ty2 >
	concept IsSame = std::is_same_v< Ty1, Ty2 >;

	template < typename Ty >
	concept IsPointer = std::is_pointer_v< Ty >;

	template < typename Ty >
	concept IsPureType = std::is_same_v< Ty, std::remove_cvref_t< Ty > >;

	template < typename Ty, typename BaseTy >
	concept IsBaseOf = std::is_base_of_v< BaseTy, Ty >;

	template < typename Ty1, typename Ty2 >
	concept IsConvertible = std::is_convertible_v< Ty1, Ty2 >;

	template < typename Ty >
	concept IsEnum = std::is_enum_v< Ty >;
}


template < typename InType, typename OutType = std::underlying_type_t< InType > > requires Rn::Concept::IsEnum< InType >
OutType EnumToValue( InType InEnum )
{
	return static_cast< OutType >(InEnum);
}

template < typename OutType, typename InType = std::underlying_type_t< OutType > > requires Rn::Concept::IsEnum< OutType >
OutType ValueToEnum( InType InValue )
{
	return static_cast< OutType >(InValue);
}


// 스레드
namespace Rn::Thread
{
	enum class EThreadType
	{
		Main,
		File,
		Render,
		Network,
		Max
	};


	inline thread_local EThreadType gCurrentThreadType = EThreadType::Max;
};
