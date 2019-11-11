#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=65536;
int n,ind[maxn],indeg[maxn];
vector<int> e[maxn];
int dfs(int x)
{
	int siz=e[x].size(),ret=1;
	for(rgi i=0;i<siz;++i)
		if(!(--ind[e[x][i]]))
			ret+=dfs(e[x][i]);
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
		while(1)
		{
			int x;
			cin>>x;
			if(!x)
				break;
			e[x].push_back(i);
			++ind[i],++indeg[i];
		}
	for(rgi i=1;i<=n;++i)
	{
		cout<<dfs(i)-1<<endl;
		for(rgi j=1;j<=n;++j)
			ind[j]=indeg[j];
	}
	return 0;
}

