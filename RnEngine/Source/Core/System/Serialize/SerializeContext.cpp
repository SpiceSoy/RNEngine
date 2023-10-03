#include "SerializeContext.h"
#include "Core/System/Serialize/Json/JsonSerializeContext.h"

// 컨텍스트를 연다
std::unique_ptr< Rn::ISerializeContext > Rn::ISerializeContext::OpenContext( const std::wstring_view InPath )
{
	return std::make_unique< JsonSerializeContext >( InPath );
}
