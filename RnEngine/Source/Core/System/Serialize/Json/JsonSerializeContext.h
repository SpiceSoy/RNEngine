// ================================================================================================
//   @file JsonSerializeContext.h
//  
//   @brief 
//   
//   @date 2023/10/04
// ================================================================================================

#pragma once
#include "Core/System/Serialize/SerializeContext.h"


namespace Rn
{
	class JsonSerializeContext : public ISerializeContext
	{
	private:
		std::wstring_view Path;

	public:
		JsonSerializeContext( std::wstring_view InPath );
	};
}
