#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=10005;
const int maxm=100005;
int n,m,u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm],dis[maxn];
bool book[maxn];
priority_queue< pii,vector<pii>,greater<pii> > que;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	while(cin>>n>>m)
	{
		memset(book,0,sizeof(book));
		memset(dis,0x3f,sizeof(dis));
		memset(fst,0,sizeof(fst));
		memset(nxt,0,sizeof(nxt));
		memset(w,0x3f,sizeof(w));
		for(rgi i=1;i<=m;++i)
		{
			cin>>u[i]>>v[i]>>w[i];
			nxt[i]=fst[u[i]];
			fst[u[i]]=i;
		}
		dis[1]=0;
		que.push(mkp(0,1));
		while(!que.empty())
		{
			int x=que.top().se;
			que.pop();
			book[x]=1;
			for(rgi i=fst[x];i;i=nxt[i])
			{
				int y=v[i];
				if(book[y])
					continue;
				if(dis[y]>dis[x]+w[i])
				{
					dis[y]=dis[x]+w[i];
					que.push(mkp(dis[y],y));
				}
			}
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}

