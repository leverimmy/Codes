#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=50005,MAXT=1005,MAXL=1000005,INF=~0U>>2;
int n,m1,m2;
int p[MAXN];
int t[MAXT];
bool vis[MAXL];
int level[MAXL];
int cnt;
int now,pre;
int minv;
int dp[2][MAXT];
int ans=INF;

void init()
{
	scanf("%d %d %d",&n,&m1,&m2);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if (!vis[p[i]]) t[++cnt]=p[i];
		vis[p[i]]=true;
	}
	sort(t+1,t+cnt+1);
	for (int i=1;i<=cnt;i++) level[t[i]]=i;
	for (int i=1;i<=n;i++) p[i]=level[p[i]];
}

inline int getdp()
{
	now=1;
	for (int i=1;i<=cnt;i++)
	{
		if (i>p[1]) dp[now][i]=m1;
		else if (i<p[1]) dp[now][i]=m2;
		else dp[now][i]=0;
	}
	for (int i=2;i<=n;i++)
	{
		now=1-now; pre=1-now;
		minv=dp[now][1]=dp[pre][1];
		for (int j=2;j<=cnt;j++)
		{
			minv=min(minv,dp[pre][j]);
			dp[now][j]=minv;
		}
		for (int j=1;j<p[i];j++) dp[now][j]+=m2;
		for (int j=p[i]+1;j<=cnt;j++) dp[now][j]+=m1;
	}
	int res=INF;
	for (int i=1;i<=cnt;i++) res=min(res,dp[now][i]);
	return res;
}

void solve()
{
	ans=getdp();
	reverse(p+1,p+n+1);
	ans=min(ans,getdp());
	printf("%d\n",ans);
}

int main()
{
	freopen ("robot.in","r",stdin);
	freopen ("robot.out","w",stdout);
	init();
	solve();
	return 0;
}
