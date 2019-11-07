#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
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
int v[110];
signed main()
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(!n)
		return 0;
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	int maxn(109);
	v[maxn]=-INF;
	for(int i=1;i<=n;i++)
		if(v[i]>v[maxn])
			maxn=i;
	printf("%d ",v[maxn]);
	for(int i=1;i<=n;i++)
		if(v[i]==v[maxn])
			printf("%d ",i-1);
	return puts("");
}
