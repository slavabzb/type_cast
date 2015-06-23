#ifndef TYPECAST_H
#define TYPECAST_H

/**
 * int, float, unsigned int, char*, std::string
 *
 * const char*  -> int, float, unsigned int, string
 * string       -> int, float, unsigned int
 * unsigned int -> int, float, string
 * float        -> int, unsigned int, string
 * int          -> float, unsigned int, string
 */

#include <string>
#include <cstdlib>
#include <cstring>
#include <stdexcept>



template< typename T, typename S >
T type_cast( S value )
{
  static_assert( !std::is_same< T, char* >::value, "type_cast to char*" );
  static_assert( !std::is_same< T, const char* >::value, "type_cast to const char*" );

  return ( static_cast< T >( value ) );
}



template< typename T > T type_cast( const char* );



template<>
int type_cast( const char* string )
{
  char* ptr;
  long int value = strtol( string, &ptr, 10 );

  bool invalid_first_character = ( *ptr == string[ 0 ] );
  bool invalid_tail = ( *ptr != string[ strlen( string ) ] );

  if ( invalid_first_character || invalid_tail ) {
    throw std::invalid_argument( "Can't convert argument" );
  }

  return ( value );
}



template<>
float type_cast( const char* string )
{
  char* ptr;
  double value = strtod( string, &ptr );

  bool invalid_first_character = ( *ptr == string[ 0 ] );
  bool invalid_tail = ( *ptr != string[ strlen( string ) ] );

  if ( invalid_first_character || invalid_tail ) {
    throw std::invalid_argument( "Can't convert argument" );
  }

  return ( value );
}



template<>
unsigned int type_cast( const char* string )
{
  char* ptr;
  unsigned long value = strtoul( string, &ptr, 10 );

  bool is_negative = ( string[ 0 ] == '-' );
  bool invalid_first_character = ( *ptr == string[ 0 ] );
  bool invalid_tail = ( *ptr != string[ strlen( string ) ] );

  if ( invalid_first_character || invalid_tail || is_negative ) {
    throw std::invalid_argument( "Can't convert argument" );
  }

  return ( value );
}



template<> std::string  type_cast( const char* string )        { return ( std::string( string ) ); }
template<> std::string  type_cast( float value )               { return ( std::to_string( value ) ); }
template<> std::string  type_cast( int value )                 { return ( std::to_string( value ) ); }
template<> std::string  type_cast( unsigned int value )        { return ( std::to_string( value ) ); }
template<> int          type_cast( const std::string& string ) { return ( type_cast< int >( string.c_str() ) ); }
template<> float        type_cast( const std::string& string ) { return ( type_cast< float >( string.c_str() ) ); }
template<> unsigned int type_cast( const std::string& string ) { return ( type_cast< unsigned int >( string.c_str() ) ); }



#endif // TYPECAST_H
