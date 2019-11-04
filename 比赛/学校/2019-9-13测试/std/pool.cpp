#include<stdio.h>
#include<algorithm>
#include<iostream>
#define LL long long
#define N 100005
#define mod 1000000007
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
  return sum;
}
int d;
LL f[N][2],sum[N];
inline int up(LL &x,LL y) {x+=y;x%=mod;}
int main( )
{
  freopen("pool.in","r",stdin);
  freopen("pool.out","w",stdout);
  int i,T=read( ),l,r;
  d=read( );
  f[0][0]=1;
  for(i=1;i<=100000;i++)
    {
      up(f[i][0],f[i-1][0]);
      up(f[i][0],f[i-1][1]);
      if(i>=d) up(f[i][1],f[i-d][0]);
    }
  for(i=1;i<=100000;i++)
    {
      sum[i]=sum[i-1];
      up(sum[i],f[i][0]+f[i][1]);
    }
  while(T--)
    {
      l=read( );r=read( );
      if(!l) printf("%lld\n",(sum[r]+1)%mod);
      else printf("%lld\n",((sum[r]-sum[l-1])%mod+mod)%mod);
    }
  return 0;
}
