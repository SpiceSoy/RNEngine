#include "RnEngine.h"
#include <iostream>

bool Rn::RnEngine::Initialize( IPlatformContext* InPlatformContext, const std::vector< std::wstring_view >& InArgument )
{
	return true;
}

void Rn::RnEngine::Tick()
{
	printf( "Tick\n" );
}

void Rn::RnEngine::Close()
{
}

void Rn::RnEngine::Finalize()
{
}

bool Rn::RnEngine::IsTerminated() const
{
	return false;
}

bool Rn::RnEngine::IsConsoleMode() const
{
	return false;
}

bool Rn::RnEngine::IsShowDebugConsole() const
{
	return true;
}
