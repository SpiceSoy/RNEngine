#include "BaseProperty.h"
#include "Core/System/Property/PropertyContainer.h"

Rn::FBaseProperty::FBaseProperty( FPropertyContainer* InContainer )
{
	if ( InContainer )
	{
		InContainer->AddProperty( *this );
	}
}

void Rn::FBaseProperty::Serialize( ISerializeContext* InContext )
{
	OnSerialize( InContext );
}

void Rn::FBaseProperty::Deserialize( ISerializeContext* InContext )
{
	OnDeserialize( InContext );
}

void Rn::FBaseProperty::NotifyPropertyChanged()
{
	OnPropertyChanged();
}
