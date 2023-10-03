// ================================================================================================
//   @file EventSender.h
//  
//   @brief 
//   
//   @date 2023/09/30
// ================================================================================================
#pragma once

#include "Core/Common/GlobalMacro.h"
#include <set>


namespace Rn
{
	// 이벤트 발신자
	template < typename Ty > requires Rn::Concept::IsRnType< Ty >
	class TBaseEventSender : IRnType
	{
		DECLARE_RN_TYPE( TBaseEventSender<Ty> )

	private:
		std::set< Ty* > Listeners;

	public:
		// 해당 이벤트 리스너가 등록되었는지 반환한다.
		bool HasEventListener( const Ty& InObject ) const
		{
			return Listeners.contains( &InObject );
		}

		// 이벤트 리스너를 등록한다.
		void AddEventListener( const Ty& InObject )
		{
			if ( HasEventListener( InObject ) ) return;

			Listeners.insert( &InObject );
		}

		// 이벤트 리스너를 지운다.
		void RemoveEventListener( const Ty& InObject )
		{
			if ( !HasEventListener( InObject ) ) return;

			Listeners.erase( &InObject );
		}

		// 이벤트를 트리거한다.
		void NotifyEvent( void (Ty::*InFunctionPtr)() )
		{
			for ( Ty* ptr : Listeners )
			{
				if ( !ptr ) continue;

				( ptr->*InFunctionPtr )();
			}
		}

		// 이벤트를 트리거한다.
		template < typename... Tys >
		void NotifyEvent( void (Ty::*InFunctionPtr)( Tys... ), Tys... InArgs )
		{
			for ( Ty* ptr : Listeners )
			{
				if ( !ptr ) continue;

				( ptr->*InFunctionPtr )( InArgs... );
			}
		}
	};
}
