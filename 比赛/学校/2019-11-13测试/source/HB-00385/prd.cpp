#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
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
std::vector<ll>u;
void dfs(ll x)
{
	if(x>1e4)
		return;
	if(x)
		u.push_back(x);
	dfs(x*10ll+7ll);
	dfs(x*10ll+4ll);
}
ll s[8191][25];
signed main()
{
	/*freopen("prd.in","r",stdin);
	freopen("prd.out","w",stdout);*/
	dfs(0);
	std::sort(u.begin(),u.end());
	u.erase(std::unique(u.begin(),u.end()),u.end());
	int n=u.size();
	for(int k=0;k<n;k++)
		for(int p=1;p<=24;p++)
			if(p==1)
				s[k][p]=u[k];
			else if(u[k]<=1e2&&s[k][p-1]*u[k]<=1e4)
			{
				s[k][p]=s[k][p-1]*u[k];
				u.push_back(s[k][p]);
			}
			else
				break;
	int T;
	scanf("%d",&T);
	for(int i=0;i<n-1;i++)
		for(int j=1;j<=20;j++)
			for(int p=i+1;p<n;p++)
				for(int q=1;q<=20;q++)
					if(log10(s[i][j])+log10(s[p][q])<12)
						u.push_back(s[i][j]*s[p][q]);
	std::sort(u.begin(),u.end());
	u.erase(std::unique(u.begin(),u.end()),u.end());
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int p=std::lower_bound(u.begin(),u.end(),x)-u.begin();
		int q=std::upper_bound(u.begin(),u.end(),y)-u.begin();
		printf("%d\n",q-p);
	}
	return 0;
}
