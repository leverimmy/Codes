#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
vector<int>rem[6010];
int r[6010][6010];
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
int c[6010][6010];
char str[6010];
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>str+1;
		for(int j=1;j<=m;j++)
			c[i][j]=str[j]-'0';
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
	for(int i=1;i<=m;i++)
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
