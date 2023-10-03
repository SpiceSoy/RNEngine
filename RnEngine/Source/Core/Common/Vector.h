// ================================================================================================
//   @file Vector.h
//  
//   @brief 
//   
//   @date 2023/10/01
// ================================================================================================

#pragma once
#include "Core/Common/GlobalMacro.h"


namespace Rn
{
	// Ty타입에 대한 2D 벡터 클래스입니다.
	template < typename Ty >
	struct FVector2D
	{
		using ThisType = FVector2D< Ty >;

		Ty X;
		Ty Y;

		FVector2D()
			: X( 0 ),
			  Y( 0 )
		{
		}

		FVector2D( Ty X, Ty Y )
			: X( X ),
			  Y( Y )
		{
		}

		FVector2D( const FVector2D& InVector2D )
			: FVector2D( InVector2D.X, InVector2D.Y )
		{
		}

		FVector2D( FVector2D&& InVector2D ) noexcept
			: FVector2D( InVector2D.X, InVector2D.Y )
		{
			InVector2D.SetX( 0 );
			InVector2D.SetY( 0 );
		}

		void SetX( Ty X )
		{
			this->X = X;
		}

		void SetY( Ty Y )
		{
			this->Y = Y;
		}

		ThisType operator+( const ThisType& InOther ) const
		{
			return ThisType( X + InOther.X, Y + InOther.Y );
		}

		ThisType& operator+=( const ThisType& InOther )
		{
			return *this = this->operator+( InOther );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType operator*( const Ty2& InValue )
		{
			return ThisType( this->X * InValue, this->Y * InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType& operator*=( const Ty2& InValue )
		{
			return *this = this->operator*( InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType operator/( const Ty2& InValue )
		{
			return ThisType( this->X / InValue, this->Y / InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType& operator/=( const Ty2& InValue )
		{
			return *this = this->operator/( InValue );
		}
	};


	// Ty타입에 대한 3D 벡터 클래스입니다.
	template < typename Ty >
	struct FVector3D
	{
		using ThisType = FVector3D< Ty >;


		union
		{
			FVector2D< Ty > Vector2D;


			struct
			{
				Ty X;
				Ty Y;
			};
		};


		Ty Z;

		FVector3D()
			: X( 0 ),
			  Y( 0 ),
			  Z( 0 )
		{
		}

		FVector3D( Ty X, Ty Y, Ty Z )
			: X( X ),
			  Y( Y ),
			  Z( Z )
		{
		}

		FVector3D( const FVector3D& InVector3D )
			: FVector3D( InVector3D.X, InVector3D.Y, InVector3D.Z )
		{
		}

		FVector3D( FVector3D&& InVector3D ) noexcept
			: FVector3D( InVector3D.X, InVector3D.Y, InVector3D.Z )
		{
			InVector3D.SetX( 0 );
			InVector3D.SetY( 0 );
			InVector3D.SetZ( 0 );
		}

		void SetX( Ty X )
		{
			this->X = X;
		}

		void SetY( Ty Y )
		{
			this->Y = Y;
		}

		void SetZ( Ty Z )
		{
			this->Z = Z;
		}

		ThisType operator+( const ThisType& InOther ) const
		{
			return ThisType( X + InOther.X, Y + InOther.Y );
		}

		ThisType& operator+=( const ThisType& InOther )
		{
			return *this = this->operator+( InOther );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType operator*( const Ty2& InValue )
		{
			return ThisType( this->X * InValue, this->Y * InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType& operator*=( const Ty2& InValue )
		{
			return *this = this->operator*( InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType operator/( const Ty2& InValue )
		{
			return ThisType( this->X / InValue, this->Y / InValue );
		}

		template < typename Ty2 > requires Concept::IsArithmetic< Ty2 >
		ThisType& operator/=( const Ty2& InValue )
		{
			return *this = this->operator/( InValue );
		}
	};


	// int32 타입에 대한 2D 벡터 클래스입니다.
	using FVector2DI = FVector2D< int32 >;

	// uint32 타입에 대한 2D 벡터 클래스입니다.
	using FVector2DU = FVector2D< uint32 >;

	// int32 타입에 대한 3D 벡터 클래스입니다.
	using FVector3DI = FVector3D< int32 >;

	// uint32 타입에 대한 3D 벡터 클래스입니다.
	using FVector3DU = FVector3D< uint32 >;

	// float 타입에 대한 2D 벡터 클래스입니다.
	using FVector2DF = FVector2D< float >;

	// float 타입에 대한 3D 벡터 클래스입니다.
	using FVector3DF = FVector3D< float >;

	// double 타입에 대한 2D 벡터 클래스입니다.
	using FVector2DD = FVector2D< double >;

	// double 타입에 대한 3D 벡터 클래스입니다.
	using FVector3DD = FVector3D< double >;
}
