// ================================================================================================
//   @file BaseProperty.h
//  
//   @brief 
//   
//   @date 2023/10/02
// ================================================================================================

#pragma once
#include <string_view>


namespace Rn
{
	class FPropertyContainer;
	class ISerializeContext;
}


namespace Rn
{
	class FBaseProperty
	{
	private:
		std::wstring Name;

	public:
		FBaseProperty( FPropertyContainer* InContainer, std::wstring_view InName );

		virtual ~FBaseProperty() = default;

		std::wstring_view GetName() const;

		virtual void Serialize( ISerializeContext* InContext );

		virtual void Deserialize( ISerializeContext* InContext );

		virtual void NotifyPropertyChanged();

	protected:
		virtual void OnSerialize( ISerializeContext* InContext ) = 0;

		virtual void OnDeserialize( ISerializeContext* InContext ) = 0;

		virtual void OnPropertyChanged() = 0;
	};
}
