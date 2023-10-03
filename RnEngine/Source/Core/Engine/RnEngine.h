// ================================================================================================
//   @file RnEngine.h
//  
//   @brief 
//   
//   @date 2023/10/01
// ================================================================================================

#pragma once
#include "Core/Common/BaseSingleton.h"
#include <vector>


namespace Rn
{
	class IPlatformContext;
}


namespace Rn
{
	// 엔진 엔트리 포인트 클래스
	class RnEngine : TBaseSingleton< RnEngine >
	{
	public:
		// 엔진을 초기화합니다.
		bool Initialize( IPlatformContext* InPlatformContext, const std::vector< std::wstring_view >& InArgument );

		// 엔진 틱
		void Tick();

		// 엔진을 종료 처리 합니다.
		void Close();

		// 엔진 종료 시의 처리를 수행합니다.
		void OnClose();

		// 종료중인지 여부를 반환합니다.
		bool IsTerminated() const;

		// 콘솔용 모드인지 여부를 반환합니다.
		bool IsConsoleMode() const;

		// 디버깅용 콘솔을 반환합니다.
		bool IsShowDebugConsole() const;

		// 인스턴스 포인터를 반환합니다.
		static RnEngine* GetInstancePtr()
		{
			return TBaseSingleton< RnEngine >::GetInstancePtr();
		}

		// 인스턴스를 반환합니다.
		static RnEngine& GetInstance()
		{
			return TBaseSingleton< RnEngine >::GetInstance();
		}
	};
}
