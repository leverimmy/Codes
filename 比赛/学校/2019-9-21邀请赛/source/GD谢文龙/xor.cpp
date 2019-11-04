#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#define reg register

int n,m,Q,flag;

struct XY{
  int x,y;

  XY( int x=0,int y=0 )
  :x(x),y(y){}
}f[ 131072 ];

int getfa( const int &x ) {
  if ( x==f[ x ].x )return x;

  int fx=f[ x ].x;

  f[ x ].x=getfa( fx ),
  f[ x ].y^=f[ fx ].y;

  return f[ x ].x;
}

int main() {
  freopen( "xor.in","r",stdin ),
  freopen( "xor.out","w",stdout );

  scanf( "%d",&Q );

  for ( ;Q;--Q ) {
    scanf( "%d%d",&n,&m ),
    flag=1;

    for ( reg int i=0;i<=n;++i )
    f[ i ]=XY( i,0 );

    for ( int x,y,z,fx,fy;m;--m ) {
      scanf( "%d%d%d",&x,&y,&z ),--x;

      if ( !flag )continue;

      fx=getfa( x ),fy=getfa( y );

      fx==fy?(
        ( f[ x ].y^f[ y ].y!=z )&&( flag=0 ) ):
      ( f[ fy ]=XY( fx,f[ x ].y^f[ y ].y^z ) );
    }

    printf( flag?"Yes\n": "No\n" );
  }

  return 0;
}
