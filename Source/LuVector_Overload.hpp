#ifndef LU_VECTOR_OVERLOAD_INCLUDED
#define LU_VECTOR_OVERLOAD_INCLUDED

#include "LuVector.hpp"

namespace LUV
{
	//////////////////////////////////////////////////////////////
	// OPERATOR OVERLOADS
	//////////////////////////////////////////////////////////////

	// OSTREAM << VECTOR
	template< size_t N, class T >
	ostream& operator <<( ostream& lhs, const LuVector< N, T >& rhs )
	{
		lhs << "(";
		UNROLL( lhs, rhs, ",", OP_OSTREAM< T >(), LOOP_INDEX< N - 2 >() );
		lhs << rhs[ N - 1 ] << ")";
		return lhs;
	}

	// VECTOR += SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator +=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_ADD< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR -= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator -=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_SUB< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR *= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator *=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_MUL< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR /= SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator /=( LuVector< N, T >& lhs, const S& rhs )
	{
		UNROLL( lhs, rhs, OP_DIV< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR += VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator +=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_ADD< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR -= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator -=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_SUB< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR *= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator *=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_MUL< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	// VECTOR /= VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T >& operator /=( LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		UNROLL( lhs, rhs, OP_DIV< T, S >(), LOOP_INDEX< N - 1 >() );
		return lhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR + SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// SCALAR + VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// VECTOR - SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// SCALAR - VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// VECTOR * SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// SCALAR * VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// VECTOR / SCALAR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const LuVector< N, T >& lhs, const S& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	// SCALAR / VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const T& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR + VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator +( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result += rhs;
	}

	// VECTOR - VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator -( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result -= rhs;
	}

	// VECTOR * VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator *( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result *= rhs;
	}

	// VECTOR / VECTOR
	template< size_t N, class T, class S >
	inline LuVector< N, T > operator /( const LuVector< N, T >& lhs, const LuVector< N, S >& rhs )
	{
		LuVector< N, T > result( lhs );
		return result /= rhs;
	}

	//////////////////////////////////////////////////////////////

	// - VECTOR
	template< size_t N, class T >
	inline LuVector< N, T > operator -( const LuVector< N, T >& vec )
	{
		return T( 0 ) - vec;
	}

	//////////////////////////////////////////////////////////////

	// VECTOR == VECTOR
	//	template< size_t N, class T, class S >
	//	inline bool operator ==( const Vec< N, T >& lhs, const Vec< N, S >& rhs )
	//	{
	//		return lhs[0] == static_cast< T >( rhs[0] ) && lhs[1] == static_cast< T >( rhs[1] ) && lhs[2] == static_cast< T >( rhs[2] );
	//	}

};

#endif