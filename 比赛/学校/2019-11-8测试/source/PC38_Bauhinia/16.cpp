#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=1005;
const int maxm=2005;
int n,m,u[maxm],v[maxm],w[maxm],dis[maxn];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	while(cin>>n>>m)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(w,0x3f,sizeof(w));
		for(rgi i=1;i<=m;++i)
			cin>>u[i]>>v[i]>>w[i];
		dis[1]=0;
		for(rgi i=1;i<=n;++i)
			for(rgi j=1;j<=m;++j)
				if(dis[v[j]]>dis[u[j]]+w[j])
					dis[v[j]]=dis[u[j]]+w[j];
		bool flag=0;
		for(rgi i=1;i<=n;++i)
		{
			for(rgi j=1;j<=m;++j)
				if(dis[v[j]]>dis[u[j]]+w[j])
				{
					cout<<"yes"<<endl;
					flag=1;
					break;
				}
			if(flag)
				break;
		}
		if(!flag)
			cout<<"no"<<endl;
	}
	return 0;
}

