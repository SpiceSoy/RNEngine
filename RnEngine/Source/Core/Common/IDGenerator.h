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
	// ID 할당기
	template < typename Ty >
	class TIDGenerator
	{
	public:
		using FObjIDType = Ty;

	private:
		const FObjIDType RangeStart;
		const FObjIDType RangeEnd;

		FObjIDType Cursor;

	public:
		// 생성자
		TIDGenerator( FObjIDType InRangeStart, FObjIDType InRangeEnd )
			: RangeStart( InRangeStart ), RangeEnd( InRangeEnd )
		{
			Reset();
		}

		// 커서를 초기화한다.
		void Reset()
		{
			Cursor = RangeStart;
		}

		// 아이디를 할당한다.
		FObjIDType AllocateID()
		{
			FObjIDType result = Cursor;

			Cursor += 1;

			return result;
		}
	};
}
