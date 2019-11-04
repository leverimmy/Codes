#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>e[100001];
int val[10001],p[10001];
int get_ans(int s)
{
	int vis[16];
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s&(1<<(i-1)))
			ans+=val[i];
	for(int u=1;u<=n;u++)
		if(!(s&(1<<(u-1))))
		{
			for(int i=0;i<e[u].size();i++)
				if(s&(1<<(e[u][i]-1))&&vis[e[u][i]]==0)
				{
					vis[e[u][i]]=1;
					ans-=p[e[u][i]];
				}
		}
	return ans;
}
int main()
{
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&val[i],&p[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
	}
	int ans=-999999999;
	for(int i=0;i<(1<<n);i++)
		ans=max(ans,get_ans(i));
	printf("%d",ans);
	return 0;
}
