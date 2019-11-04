#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<ext\pb_ds\assoc_container.hpp>
#include<ext\pb_ds\priority_queue.hpp>
#define reg register
const int N=131072;

int n,m,cost[ N ],ans;

struct XY{
  int t,c;

  inline bool operator <( const XY &las ) const {
    return c>las.c;
  }

  XY( int t=0,int c=0 )
  :t(t),c(c){}
};

std::vector<XY> eto[ N ];
__gnu_pbds::priority_queue<XY> que;
__gnu_pbds::priority_queue<XY>::point_iterator its[ N ];

int main() {
  freopen( "tree.in","r",stdin ),
  freopen( "tree.out","w",stdout );

  scanf( "%d%d",&n,&m );

  for ( int x,y,z;m;--m )
  scanf( "%d%d%d",&x,&y,&z ),
  eto[ x ].push_back( XY( y,z ) ),
  eto[ y ].push_back( XY( x,z ) );

  for ( reg int i=2;i<=n;++i )
  its[ i ]=que.push( XY( i,cost[ i ]=100000 ) );

  its[ 1 ]=que.push( XY( 1,cost[ 1 ]=0 ) );

  while ( !que.empty() ) {
    int x=que.top().t,c=cost[ x ],t,mx;
    que.pop(),ans+=c;

    for ( std::vector<XY>::iterator it=eto[ x ].begin(),ed=eto[ x ].end();
          it!=ed;++it )
    if ( cost[ t=it->t ]>( mx=std::max( c,it->c ) ) )
    que.modify( its[ t ],XY( t,cost[ t ]=mx ) );
  }

  printf( "%d",ans );

  return 0;
}
