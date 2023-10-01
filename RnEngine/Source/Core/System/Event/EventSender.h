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
	//----------------------------------------------------------------------
	//! @brief
	//! @tparam
	//----------------------------------------------------------------------
	export template < typename Ty > requires Rn::Concept::IsRnType< Ty >
	class TBaseEventSender : IRnType
	{
		DECLARE_RN_TYPE( TBaseEventSender<Ty> )

	private:
		std::set< Ty* > Listeners;

	public:
		//----------------------------------------------------------------------
		//! @brief
		//! @param InObject
		//! @return
		//----------------------------------------------------------------------
		bool HasEventListener( const Ty& InObject ) const
		{
			return Listeners.contains( &InObject );
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @param InObject
		//! @return
		//----------------------------------------------------------------------
		void AddEventListener( const Ty& InObject )
		{
			if ( HasEventListener( InObject ) ) return;

			Listeners.insert( &InObject );
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @param InObject
		//----------------------------------------------------------------------
		void RemoveEventListener( const Ty& InObject )
		{
			if ( !HasEventListener( InObject ) ) return;

			Listeners.erase( &InObject );
		}

		//----------------------------------------------------------------------
		//! @brief
		//----------------------------------------------------------------------
		void NotifyEvent( void (Ty::*InFunctionPtr)() )
		{
			for ( Ty* ptr : Listeners )
			{
				if ( !ptr ) continue;

				( ptr->*InFunctionPtr )();
			}
		}

		//----------------------------------------------------------------------
		//! @brief
		//----------------------------------------------------------------------
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
