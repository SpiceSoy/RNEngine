// ================================================================================================
//   @file BaseSingleton.h
//
//   @brief
//
//   @date 2023/10/01
// ================================================================================================

#pragma once

#include "Core/Common/GlobalMacro.h"
#include <memory>


namespace Rn
{
	// Ty를 싱글톤으로 만들어주는 템플릿 클래스
	template < typename Ty >
	class TBaseSingleton
	{
	private:
		inline static std::unique_ptr< Ty > instancePtr;

	protected:
		// 생성자
		TBaseSingleton()
		{
		}

		// 소멸자
		virtual ~TBaseSingleton()
		{
		}

		// 인스턴스 포인터를 반환한다.
		static Ty* GetInstancePtr()
		{
			if ( instancePtr == nullptr )
			{
				instancePtr = std::make_unique< Ty >();
			}

			return instancePtr.get();
		}

		// 인스턴스를 반환한다.
		static Ty& GetInstance()
		{
			if ( instancePtr == nullptr )
			{
				instancePtr = std::make_unique< Ty >();
			}

			return *instancePtr;
		}

	public:
		// 초기화한다.
		virtual void Initialize()
		{
		}

		// 게임 시작됨을 처리한다.
		virtual void StartPlay()
		{
		}

		// 틱을 처리한다
		virtual void Tick( float InDeltaTime )
		{
		}

		// 게임 종료됨을 처리한다.
		virtual void EndPlay()
		{
		}
	};
}
