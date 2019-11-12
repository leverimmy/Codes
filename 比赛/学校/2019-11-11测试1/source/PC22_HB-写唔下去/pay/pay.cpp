#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=205;
int n,m,g,d;
int a[maxn][maxn],b[maxn][maxn];

void dfs(int num)
{
	if(num==m+1)
	{
		if(check())
		{
			ans=min(ans,getval());
			
		}
	}
		
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("pay.in","r",stdin);
	//freopen("pay.out","w",stdout);
	cin>>n>>m;
	memset(a,0x7f,sizeof(a));
	memset(b,0x7f,sizeof(b));
	int maxa=0,maxb=0;
	for(rgi i=1;i<=m;++i)
	{
		int x,y,z,w;
		cin>>x>>y>>z>>w;
		a[x][y]=z,b[x][y]=w;
		maxa=max(maxa,z);
		maxb=max(maxb,z);
	}
	dfs(1);
	
	return 0;
}

