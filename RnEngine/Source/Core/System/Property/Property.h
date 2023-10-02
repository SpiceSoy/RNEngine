// ================================================================================================
//   @file Property.h
//  
//   @brief 
//   
//   @date 2023/10/01
// ================================================================================================
#pragma once

#include "Core/System/Property/BaseProperty.h"


namespace Rn
{
	template < typename ValueTy >
	struct TPropertyMutator;


	template < typename ValueTy >
	struct TBaseProperty : FBaseProperty
	{
		friend struct TPropertyMutator< ValueTy >;

	private:
		ValueTy Value;

	public:
		TBaseProperty& operator=( const TBaseProperty& InProperty )
		{
			*this = InProperty.Value;

			return *this;
		}

		TBaseProperty& operator=( const ValueTy& InValue )
		{
			Value = InValue;

			NotifyPropertyChanged();

			return *this;
		}

		operator ValueTy() const
		{
			return Value;
		}
	};


	template < typename ValueTy >
	struct TPropertyMutator
	{
	private:
		bool                      IsChanged = false;
		TBaseProperty< ValueTy >& PropertyInstance;

	public:
		TPropertyMutator( TBaseProperty< ValueTy >& InInstance )
			: PropertyInstance( InInstance )
		{
		}

		~TPropertyMutator()
		{
			if ( IsChanged )
			{
				PropertyInstance.NotifyPropertyChanged();
			}
		}

		ValueTy& operator*()
		{
			IsChanged = true;

			return PropertyInstance.Value;
		}

		ValueTy* operator->()
		{
			IsChanged = true;

			return PropertyInstance.Value;
		}
	};


	template < typename ValueTy >
	struct TProperty : TBaseProperty< ValueTy >
	{
	public:
		TPropertyMutator< ValueTy > GetMutator()
		{
			return TPropertyMutator< ValueTy >( *this );
		}
	};
}
