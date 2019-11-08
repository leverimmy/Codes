#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int 
using namespace std;
int n,m,e,a[1003][1003],ans,match[1003];
bool book[1003];
inline bool dfs(int x)
{
	for(rgi i=1;i<=n;++i)
		if(!book[i]&&a[x][i])
		{
			book[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	cin>>n>>e;
	m=n;
	for(rgi i=1;i<=e;++i)
	{
		int p,q;
		cin>>p>>q;
		if(p>n||q>m)
			continue;
		a[p][q]=1;
	}
	for(rgi i=1;i<=n;++i)
	{
		for(rgi j=1;j<=n;++j)
			book[j]=0;
		if(dfs(i))
			++ans;
	}
	cout<<ans<<endl;
}

