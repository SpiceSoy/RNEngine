#include "PropertyContainer.h"
#include "Core/System/Property/BaseProperty.h"
#include <algorithm>

void Rn::FPropertyContainer::Reserve( uint32 InSize )
{
	Properties.reserve( InSize );
}

void Rn::FPropertyContainer::Serialize( ISerializeContext* InContext )
{
	auto ftrEach = [InContext] ( FBaseProperty* InProperty )
	{
		InProperty->Serialize( InContext );
	};

	std::ranges::for_each( Properties, ftrEach );
}

void Rn::FPropertyContainer::Deserialize( ISerializeContext* InContext )
{
	auto ftrEach = [InContext] ( FBaseProperty* InProperty )
	{
		InProperty->Deserialize( InContext );
	};

	std::ranges::for_each( Properties, ftrEach );
}

void Rn::FPropertyContainer::AddProperty( FBaseProperty& InProperty )
{
	Properties.push_back( &InProperty );
}
