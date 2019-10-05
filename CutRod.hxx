#ifndef __PUJ__CutRod__hxx__
#define __PUJ__CutRod__hxx__

template< class _TPrices, class _TCuts >
void PUJ::
CutRod( _TCuts& cuts, const _TPrices& P, long n )
{
  typedef typename _TPrices::value_type _TValue;

  _TPrices r( n + 1 );
  _TCuts s( n + 1 );

  r[ 0 ] = _TValue( 0 );
  for( long j = 1; j <= n; ++j )
  {
    r[ j ] = std::numeric_limits< _TValue >::lowest( );
    for( long k = 1; k <= j; ++k )
    {
      _TValue v = P[ k ] + r[ j - k ];
      if( r[ j ] < v )
      {
        r[ j ] = v;
        s[ j ] = k;
      } // end if
    } // end for
  } // end for

  long m = n;
  while( m > 0 )
  {
    cuts.push_back( s[ m ] );
    m -= s[ m ];
  } // end while
}

#endif // __PUJ__CutRod__hxx__

// eof - CutRod.hxx
