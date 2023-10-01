// ================================================================================================
//   @file BaseProperty.h
//  
//   @brief 
//   
//   @date 2023/10/02
// ================================================================================================

#pragma once

namespace Rn
{
	class FBaseProperty
	{
	public:
		virtual ~FBaseProperty() = default;

		virtual void Serialize();

		virtual void Deserialize();

		virtual void NotifyChange();

	protected:
		virtual void OnSerialize() = 0;

		virtual void OnDeserialize() = 0;

		virtual void OnPropertyChanged() = 0;
	};
}
