// ================================================================================================
//   @file SerializeContext.h
//  
//   @brief 
//   
//   @date 2023/10/02
// ================================================================================================

#pragma once
#include "Core/Common/Vector.h"
#include "Platform/Core/PlatformDefine.h"
#include <memory>
#include <string_view>


namespace Rn
{
	class FPropertyContainer;


	// 직렬화 / 역직렬화 인터페이스
	class ISerializeContext
	{
	public:
		ISerializeContext()
		{
		}

		virtual ~ISerializeContext()
		{
		}

		virtual void Open() = 0;

		virtual void Close() = 0;

		// int8 직렬화 함수
		virtual void Serialize( const int8& InValue ) = 0;

		// int16 직렬화 함수
		virtual void Serialize( const int16& InValue ) = 0;

		// int32 직렬화 함수
		virtual void Serialize( const int32& InValue ) = 0;

		// int64 직렬화 함수
		virtual void Serialize( const int64& InValue ) = 0;

		// uint8 직렬화 함수
		virtual void Serialize( const uint8& InValue ) = 0;

		// uint16 직렬화 함수
		virtual void Serialize( const uint16& InValue ) = 0;

		// uint32 직렬화 함수
		virtual void Serialize( const uint32& InValue ) = 0;

		// uint64 직렬화 함수
		virtual void Serialize( const uint64& InValue ) = 0;

		// float 직렬화 함수
		virtual void Serialize( const float& InValue ) = 0;

		// double 직렬화 함수
		virtual void Serialize( const double& InValue ) = 0;

		// FVector2D int32 직렬화 함수
		virtual void Serialize( const FVector2DI& InValue ) = 0;

		// FVector2D uint32 직렬화 함수
		virtual void Serialize( const FVector2DU& InValue ) = 0;

		// FVector2D float 직렬화 함수
		virtual void Serialize( const FVector2DF& InValue ) = 0;

		// FVector2D double 직렬화 함수
		virtual void Serialize( const FVector2DD& InValue ) = 0;

		// FVector3D int32 직렬화 함수
		virtual void Serialize( const FVector3DI& InValue ) = 0;

		// FVector3D uint32 직렬화 함수
		virtual void Serialize( const FVector3DU& InValue ) = 0;

		// FVector3D float 직렬화 함수
		virtual void Serialize( const FVector3DF& InValue ) = 0;

		// FVector3D double 직렬화 함수
		virtual void Serialize( const FVector3DD& InValue ) = 0;

		// 문자열 직렬화 함수
		virtual void Serialize( std::wstring_view InValue ) = 0;

		// 문자열 직렬화 함수
		virtual void Serialize( const std::wstring& InValue ) = 0;

		// 프로퍼티 클래스 직렬화 함수
		virtual void Serialize( const FPropertyContainer& InContainer ) = 0;

		// 컨텍스트를 연다
		static std::unique_ptr< ISerializeContext > OpenContext( std::wstring_view InPath );
	};
}
