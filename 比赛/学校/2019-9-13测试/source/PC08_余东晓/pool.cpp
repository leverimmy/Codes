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
#define mod 1000000007ll
struct node{int x,y;}a[100010];ll f[100010][2],S[100010];
signed main()
{
	freopen("pool.in","r",stdin);freopen("pool.out","w",stdout);int T,k,n(0);scanf("%d%d",&T,&k);for(int i=1;i<=T;i++){scanf("%d%d",&a[i].x,&a[i].y);n=std::max(n,a[i].y);}f[0][0]=1;f[0][1]=0;
	for(int i=1;i<=n;i++){f[i][0]=(f[i-1][0]+f[i-1][1])%mod;if(i-k>=0)f[i][1]=f[i-k][0];}for(int i=1;i<=n;i++)S[i]=(S[i-1]+f[i][0]+f[i][1])%mod;for(int i=1;i<=T;i++)printf("%lld\n",(S[a[i].y]-S[a[i].x-1]+mod)%mod);return 0;
}
