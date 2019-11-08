#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
const int maxn=1000010;
int prime[maxn],nprime[maxn],tot;
signed main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	int n;
	scanf("%d",&n);
	nprime[0]=nprime[1]=1;
	for (int i=2;i<=n;++i)
	{
		if(!nprime[i]) 
			prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;++j)
		{
			nprime[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=1;i<=n;++i)
		if(!nprime[i])
			printf("%d ",i);
	return puts(""),0;
}
