#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
#define INF 0x3f3f3f3f
struct fr{ll x,y;fr(){}fr(ll x,ll y):x(x),y(y){}}a[100010];ll gcd(ll x,ll y){if(x%y==0)return y;return gcd(y,x%y);}fr up(fr x){ll g=gcd(x.x,x.y);return fr(x.x/g,x.y/g);}
fr operator +(fr x,fr y){return up(fr(x.x*y.y+y.x*x.y,x.y*y.y));}fr operator -(fr x,fr y){return up(fr(x.x*y.y-y.x*x.y,x.y*y.y));}bool operator <(fr x,fr y){return x.x*y.y<y.x*x.y;}
signed main()
{
	freopen("noon.in","r",stdin);freopen("noon.out","w",stdout);int n,m;scanf("%d%d",&n,&m);a[0]=fr(1,INF);for(int i=1;i<=n;i++)a[i]=fr(-1,i);
	if(n<=1000&m<=1000){while(m--){ll x,p;int ans(0);scanf("%lld%lld",&x,&p);a[x]=fr(p,x);fr lmax=a[0];for(int i=1;i<=n;i++)if(lmax<a[i]){lmax=a[i];ans++;}printf("%d\n",ans);}return 0;}
	fr minl=a[0];int ans(0);while(m--){int x,p;scanf("%d%d",&x,&p);if(minl<fr(x,p)){ans++;minl=fr(x,p);}printf("%d\n",ans);}return 0;
}
