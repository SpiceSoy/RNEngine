// ================================================================================================
//   @file IDWrapper.h
//  
//   @brief 
//   
//   @date 2023/09/30
// ================================================================================================

#pragma once

#include "Core/Common/GlobalMacro.h"
#include <functional>


namespace Rn
{
	template < class Ty, Ty InvalidValue = 0 > requires Rn::Concept::IsIdType< Ty >
	class TIDWrapper
	{
	private:
		Ty ID = InvalidValue;

	public:
		static constexpr Ty InvalidID = InvalidValue;

	public:
		//----------------------------------------------------------------------
		//! @brief
		//! @param InId
		//----------------------------------------------------------------------
		explicit TIDWrapper( Ty InId )
			: ID( InId )
		{
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @return
		//----------------------------------------------------------------------
		Ty GetValue() const
		{
			return ID;
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @param InRhs
		//! @return
		//----------------------------------------------------------------------
		bool operator==( const TIDWrapper& InRhs ) const
		{
			return ID == InRhs.ID;
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @param InRhs
		//! @return
		//----------------------------------------------------------------------
		TIDWrapper& operator=( const TIDWrapper& InRhs ) const
		{
			ID = InRhs;

			return *this;
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @return
		//----------------------------------------------------------------------
		TIDWrapper GetInvalidID() const
		{
			return TIDWrapper( InvalidValue );
		}
	};
}
