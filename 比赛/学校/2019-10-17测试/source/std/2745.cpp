#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 3e5+100;

int T,n,fa;
int val[maxn];
int ans = 0;
vector<int> f[maxn];

void dfs(int u,int fa,int dep)
{
	if(dep&1) ans^=val[u];
	for(int i=0;i<f[u].size();i++)
	{
		int v = f[u][i];
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}

int main()
{	freopen("2745.in","r",stdin);
		freopen("2745.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		scanf("%d",&n);
		for(int i=0;i<=n;i++) f[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d",&fa);
			f[i].push_back(fa);
			f[fa].push_back(i);
		}
		for(int i=0;i<n;i++) scanf("%d",val+i);
		dfs(0,-1,0);
		if(ans) puts("win");
		else puts("lose");
	}
	return 0;
}
