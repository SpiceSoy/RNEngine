// ================================================================================================
//   @file EventSystem.h
//  
//   @brief 
//   
//   @date 2023/09/30
// ================================================================================================
#pragma once

#include "Core/Common/GlobalMacro.h"
#include "Core/System/Event/BaseDelegate.h"
#include <functional>
#include <map>


namespace Rn
{
	using FEventHandle = uint64;


	// 이벤트베이스
	template < typename Ty1 = void, typename Ty2 = void, typename Ty3 = void, typename Ty4 = void >
	class TBaseEvent : public IRnType
	{
		DECLARE_RN_TYPE( TBaseEvent )

	private:
		using FThisDelegate = TBaseDelegate< void, Ty1, Ty2, Ty3, Ty4 >;
		using FThisDelegateList = std::list< FThisDelegate >;
		using FHandleDelegateMap = std::map< FEventHandle, FThisDelegate >;
		using FPtrDelegateMap = std::map< void*, FThisDelegate >;
		using FFunctionType = typename FThisDelegate::FFunctionType;

	private:
		FHandleDelegateMap HandleDelegateMap;
		FPtrDelegateMap    PtrDelegateMap;

		FEventHandle LastHandle = 0;

	public:
		// 이벤트를 추가한다.
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		void AddEvent( Ty&& InFunctor )
		{
			while ( !AddEventByID( _GetNewId() ) );
		}

		// ID를 지정하여 이벤트를 추가한다.
		template < typename Ty > requires Concept::IsSame< Ty, FFunctionType >
		bool AddEventByID( FEventHandle InHandle, Ty&& InFunctor )
		{
			if ( !HasHandle( InHandle ) )
			{
				HandleDelegateMap[ InHandle ] = std::forward< Ty >( InFunctor );

				return true;
			}

			return false;
		}

		// 클래스를 지정하여 이벤트를 추가한다.
		template < typename ListenerTyPtr, typename Ty > requires Rn::Concept::IsSame< Ty, FFunctionType > && Rn::Concept::IsPointer< ListenerTyPtr >
		void AddEventByClass( ListenerTyPtr Ptr, Ty&& InFunctor )
		{
			PtrDelegateMap[ Ptr ].emplace_back( InFunctor );
		}

		// 해당 핸들의 이벤트를 보유중인지 확인한다.
		bool HasHandle( FEventHandle InHandle ) const
		{
			return HandleDelegateMap.contains( InHandle ) != 0;
		}

		// 해당 클래스의 이벤트를 보유중인지
		template < typename ListenerTyPtr > requires Rn::Concept::IsPointer< ListenerTyPtr >
		bool HasClass( ListenerTyPtr InPtr ) const
		{
			return PtrDelegateMap.contains( InPtr );
		}

		// 해당 핸들에 맞는 이벤트를 삭제한다.
		void RemoveHandle( FEventHandle InHandle )
		{
			if ( HasHandle( InHandle ) )
			{
				HandleDelegateMap.erase( InHandle );
			}
		}

		// 해당 클래스에 맞는 이벤트를 삭제한다.
		template < typename ListenerTyPtr > requires Rn::Concept::IsPointer< ListenerTyPtr >
		void RemoveClass( ListenerTyPtr InPtr )
		{
			if ( HasClass( InPtr ) )
			{
				PtrDelegateMap.erase( InPtr );
			}
		}

	private:
		// 새 아이디를 할당한다.
		FEventHandle _GetNewID()
		{
			do
			{
				LastHandle += 1;
			}
			while ( HasHandle( LastHandle ) );

			return LastHandle;
		}
	};
}
