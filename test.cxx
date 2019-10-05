#include <iostream>
#include <iterator>
#include <vector>
#include "CutRod.h"

int main( int argc, char* argv[] )
{
  std::vector< float > prices;
  prices.push_back( 0 );
  prices.push_back( 1 );
  prices.push_back( 5 );
  prices.push_back( 8 );
  prices.push_back( 9 );

  std::vector< long > cuts;
  PUJ::CutRod( cuts, prices, 4 );

  std::copy(
    cuts.begin( ), cuts.end( ),
    std::ostream_iterator< long >( std::cout, " " )
    );
  std::cout << std::endl;
  return( 0 );
}
