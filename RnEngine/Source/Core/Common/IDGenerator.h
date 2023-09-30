// ================================================================================================
//   @file IDGenerator.h
//  
//   @brief 
//   
//   @date 2023/10/01
// ================================================================================================

#pragma once

namespace Rn
{
	//----------------------------------------------------------------------
	//! @brief
	//! @tparam
	//----------------------------------------------------------------------
	export template < typename Ty >
	class TIDGenerator
	{
	public:
		using FObjIDType = Ty;

	private:
		const FObjIDType RangeStart;
		const FObjIDType RangeEnd;

		FObjIDType Cursor;

	public:
		//----------------------------------------------------------------------
		//! @brief
		//! @param InRangeStart
		//! @param InRangeEnd
		//----------------------------------------------------------------------
		TIDGenerator( FObjIDType InRangeStart, FObjIDType InRangeEnd )
			: RangeStart( InRangeStart ), RangeEnd( InRangeEnd )
		{
		}

		//----------------------------------------------------------------------
		//! @brief
		//----------------------------------------------------------------------
		void Initialize()
		{
			Cursor = RangeStart;
		}

		//----------------------------------------------------------------------
		//! @brief
		//! @return
		//----------------------------------------------------------------------
		FObjIDType AllocateID()
		{
			FObjIDType result = Cursor;

			Cursor += 1;

			return result;
		}
	};
}
