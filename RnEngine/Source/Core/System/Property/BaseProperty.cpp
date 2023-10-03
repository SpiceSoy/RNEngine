#include "BaseProperty.h"
#include "Core/System/Property/PropertyContainer.h"

Rn::FBaseProperty::FBaseProperty( FPropertyContainer* InContainer, const std::wstring_view InName )
{
	if ( InContainer )
	{
		InContainer->AddProperty( *this );
	}

	Name = InName;
}

std::wstring_view Rn::FBaseProperty::GetName() const
{
	return Name;
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
