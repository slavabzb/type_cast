#include <iostream>

#include "TypeCast.h"



int main()
{
  // const char*
  type_cast< int >( "123" );
  type_cast< float >( "123.4" );
  type_cast< unsigned int >( "123" );
  type_cast< std::string >( "123" );

  // std::string
  type_cast< int >( std::string( "123" ) );
  type_cast< float >( std::string( "123.4" ) );
  type_cast< unsigned int >( std::string( "123" ) );

  // unsigned int
  type_cast< int >( 123u );
  type_cast< float >( 123u );
  type_cast< std::string >( 123u );

  // float
  type_cast< int >( 123.4f );
  type_cast< unsigned int >( 123.4f );
  type_cast< std::string >( 123.4f );

  // int
  type_cast< float >( 123 );
  type_cast< unsigned int >( 123 );
  type_cast< std::string >( 123 );

  return 0;
}

