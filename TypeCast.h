#ifndef TYPECAST_H
#define TYPECAST_H

#include <string>
#include <cstdlib>
#include <cstring>
#include <stdexcept>



template< typename T, typename S >
T type_cast( const S& );




template< typename T >
T type_cast( const char* );



template<>
int type_cast< int >( const char* string )
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
int type_cast< int, std::string >( const std::string& string )
{
  return ( type_cast< int >( string.c_str() ) );
}



#endif // TYPECAST_H
