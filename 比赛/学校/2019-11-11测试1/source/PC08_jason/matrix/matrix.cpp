#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
vector<int>rem[5001];
int r[5001][5001];
int get()
{
	int res=0,tot=0;
	for(int i=m;i>=1;i--)
	{
		tot+=v[i];
		res=max(res,tot*i);
	}
	return res;
}
int c[5001][5001];
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%1d",&c[i][j]);
		for(int j=m;j>=1;j--)
		{
			if(c[i][j]==1)
			{
				r[i][j]=r[i][j+1]+1;
				if(c[i][j-1]==0)
					rem[j].push_back(r[i][j]);
			}
			else
				r[i][j]=0;
		}
	}
	int ans=0;
	v.resize(m+1);
	for(int i=1;i<=n;i++)
	{
		v.erase(v.begin());
		v.resize(m+1);
		for(int j=0;j<rem[i].size();j++)
			v[rem[i][j]]++;
		ans=max(ans,get());
	}
	printf("%d",ans);
	return 0;
}
