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
	// ID 하드타입용 래퍼 클래스
	template < class Ty, Ty InvalidValue = 0 > requires Rn::Concept::IsIDType< Ty >
	class TIDWrapper
	{
	private:
		Ty ID = InvalidValue;

	public:
		static constexpr Ty InvalidID = InvalidValue;

	public:
		// 생성자
		explicit TIDWrapper( Ty InId )
			: ID( InId )
		{
		}

		// ID Raw 값을 반환한다.
		Ty GetValue() const
		{
			return ID;
		}

		// == 연산자 오버로딩
		bool operator==( const TIDWrapper& InRhs ) const
		{
			return ID == InRhs.ID;
		}

		// = 연산자 오버로딩
		TIDWrapper& operator=( const TIDWrapper& InRhs ) const
		{
			ID = InRhs;

			return *this;
		}

		// null 아이디를 반환한다.
		TIDWrapper GetInvalidID() const
		{
			return TIDWrapper( InvalidValue );
		}
	};
}
