#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#define reg register
const int N=131072;

int n,b,m,a[ N ],c[ N ],ans[ N ];

struct Q{
  int p,k;
}q[ N ];

int main() {
  freopen( "array.in","r",stdin ),
  freopen( "array.out","w",stdout );

  scanf( "%d",&n ),b=sqrt( n );

  for ( reg int i=1;i<=n;++i )
  scanf( "%d",a+i );

  scanf( "%d",&m );

  for ( reg int i=1,k;i<=m;++i ) {
    scanf( "%d%d",&q[ i ].p,&q[ i ].k ),k=q[ i ].k;

    if ( k>=b )
    for ( reg int p=q[ i ].p,&s=ans[ i ];
          p<=n;p+=a[ p ]+k,++s );
  }

  for ( reg int k=0;k<b;++k ) {
    for ( reg int i=n,t;i;--i )
    c[ i ]=( t=i+a[ i ]+k )>n?1: c[ t ]+1;

    for ( reg int i=1;i<=m;++i )
    q[ i ].k==k&&( ans[ i ]=c[ q[ i ].p ] );
  }

  for ( reg int i=1;i<=m;++i )
  printf( "%d\n",ans[ i ] );

  return 0;
}
