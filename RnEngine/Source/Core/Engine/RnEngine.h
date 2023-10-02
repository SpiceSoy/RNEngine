// ================================================================================================
//   @file RnEngine.h
//  
//   @brief 
//   
//   @date 2023/10/01
// ================================================================================================

#pragma once
#include "Core/Common/Singleton.h"
#include <vector>


namespace Rn
{
	class IPlatformContext;
}


namespace Rn
{
	class RnEngine : TBaseSingleton< RnEngine >
	{
	public:
		bool Initialize( IPlatformContext* InPlatformContext, const std::vector< std::wstring_view >& InArgument );

		void Tick();

		void Close();

		void Finalize();

		bool IsTerminated() const;

		bool IsConsoleMode() const;

		bool IsShowDebugConsole() const;

		static RnEngine* GetInstancePtr()
		{
			return TBaseSingleton< RnEngine >::GetInstancePtr();
		}

		static RnEngine& GetInstance()
		{
			return TBaseSingleton< RnEngine >::GetInstance();
		}
	};
}
