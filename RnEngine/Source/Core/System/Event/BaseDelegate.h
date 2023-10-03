// =================================================================================================
//  @file BaseDelegate.ixx
//
//  @brief 상세 설명을 입력하시오
//
//  @date 2022/12/25
// =================================================================================================
#pragma once

#include "Core/Common/GlobalMacro.h"
#include <functional>
#include <map>


namespace Rn
{
	// 베이스 델리게이트 인자 4개 선언
	template < typename ReturnType, typename Ty1, typename Ty2, typename Ty3, typename Ty4 > requires Concept::IsNotVoids< Ty1, Ty2, Ty3, Ty4 >
	class _BaseTDelegate
	{
	public:
		using FFunctionType = std::function< ReturnType( Ty1, Ty2, Ty3, Ty4 ) >;

	protected:
		FFunctionType Functor;

	public:
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void Add( Ty&& InFunctor )
		{
			Functor = std::forward< Ty >( InFunctor );
		}

		ReturnType Invoke( const Ty1& InOne, const Ty2& InTwo, const Ty3& InThree, const Ty4& InFour )
		{
			return Functor( InOne, InTwo, InThree, InFour );
		}
	};


	// 베이스 델리게이트 인자 3개 선언
	template < typename ReturnType, typename Ty1, typename Ty2, typename Ty3 > requires Concept::IsNotVoids< Ty1, Ty2, Ty3 >
	class _BaseTDelegate< ReturnType, Ty1, Ty2, Ty3, void >
	{
	public:
		using FFunctionType = std::function< ReturnType( Ty1, Ty2, Ty3 ) >;

	protected:
		FFunctionType Functor;

	public:
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void Add( Ty&& InFunctor )
		{
			Functor = std::forward< Ty >( InFunctor );
		}

		ReturnType Invoke( const Ty1& InOne, const Ty2& InTwo, const Ty3& InThree )
		{
			return Functor( InOne, InTwo, InThree );
		}
	};


	// 베이스 델리게이트 인자 2개 선언
	template < typename ReturnType, typename Ty1, typename Ty2 > requires Concept::IsNotVoids< Ty1, Ty2 >
	class _BaseTDelegate< ReturnType, Ty1, Ty2, void, void >
	{
	public:
		using FFunctionType = std::function< ReturnType( Ty1, Ty2 ) >;

	protected:
		FFunctionType Functor;

	public:
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void Add( Ty&& InFunctor )
		{
			Functor = std::forward< Ty >( InFunctor );
		}

		ReturnType Invoke( const Ty1& InOne, const Ty2& InTwo )
		{
			return Functor( InOne, InTwo );
		}
	};


	// 베이스 델리게이트 인자 1개 선언
	template < typename ReturnType, typename Ty1 > requires Concept::IsNotVoid< Ty1 >
	class _BaseTDelegate< ReturnType, Ty1, void, void, void >
	{
	public:
		using FFunctionType = std::function< ReturnType( Ty1 ) >;

	protected:
		FFunctionType Functor;

	public:
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void Add( Ty&& InFunctor )
		{
			Functor = std::forward< Ty >( InFunctor );
		}

		ReturnType Invoke( const Ty1& InOne )
		{
			return Functor( InOne );
		}
	};


	// 베이스 델리게이트 인자 없음 선언
	template < typename ReturnType >
	class _BaseTDelegate< ReturnType, void, void, void, void >
	{
	public:
		using FFunctionType = std::function< ReturnType( void ) >;

	protected:
		FFunctionType Functor;

	public:
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void Add( Ty&& InFunctor )
		{
			Functor = std::forward< Ty >( InFunctor );
		}

		ReturnType Invoke()
		{
			return Functor();
		}
	};


	// 델리게이트
	template < typename ReturnType = void, typename Ty1 = void, typename Ty2 = void, typename Ty3 = void, typename Ty4 = void >
	class TBaseDelegate : public IRnType, public _BaseTDelegate< ReturnType, Ty1, Ty2, Ty3, Ty4 >
	{
		DECLARE_RN_TYPE( TBaseDelegate )
	};
}
