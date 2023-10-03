#include "RnEngine.h"
#include <iostream>

// 엔진을 초기화합니다.
bool Rn::RnEngine::Initialize( IPlatformContext* InPlatformContext, const std::vector< std::wstring_view >& InArgument )
{
	return true;
}

// 엔진 틱
void Rn::RnEngine::Tick()
{
}

// 엔진을 종료 처리 합니다.
void Rn::RnEngine::Close()
{
}

// 엔진 종료 시의 처리를 수행합니다.
void Rn::RnEngine::OnClose()
{
}

// 종료중인지 여부를 반환합니다.
bool Rn::RnEngine::IsTerminated() const
{
	return false;
}

// 콘솔용 모드인지 여부를 반환합니다.
bool Rn::RnEngine::IsConsoleMode() const
{
	return false;
}

// 디버깅용 콘솔을 반환합니다.
bool Rn::RnEngine::IsShowDebugConsole() const
{
	return true;
}
