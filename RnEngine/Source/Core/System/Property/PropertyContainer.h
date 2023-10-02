// ================================================================================================
//   @file PropertyContainer.h
//  
//   @brief 
//   
//   @date 2023/10/02
// ================================================================================================

#pragma once
#include "Platform/Core/PlatformDefine.h"
#include <vector>


namespace Rn
{
	class ISerializeContext;
	class FBaseProperty;
}


namespace Rn
{
	class FPropertyContainer
	{
		friend FBaseProperty;

	private:
		std::vector< FBaseProperty* > Properties;

	public:
		void Reserve( uint32 InSize );

		void Serialize( ISerializeContext* InContext );

		void Deserialize( ISerializeContext* InContext );

	private:
		void AddProperty( FBaseProperty& InProperty );
	};
}
