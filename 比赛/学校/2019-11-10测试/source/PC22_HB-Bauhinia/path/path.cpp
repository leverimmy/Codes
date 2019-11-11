#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=100005;
const int maxm=maxn<<1;
int n,m,u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm],fa[maxn],pairs[maxm],ans=2147483647;
bool book[maxn],edge[maxm],poi[maxn];
int bfs(int s)
{
	int ret=0,pos=0,d=0;
	queue<pii> que;
	que.push(mkp(s,0));
	book[s]=1;
	while(!que.empty())
	{
		int x=que.front().fi,val=que.front().se;
		if(val>d)
			pos=x,d=val;
		que.pop();
		for(rgi i=fst[x];i;i=nxt[i])
		{
			int y=v[i];
			if(book[y])
				continue;
			book[y]=1;
			fa[y]=i;
			que.push(mkp(y,val+w[i]));
		}
	}
	for(rgi i=fa[pos];i;i=fa[u[i]])
		edge[i]=1,edge[pairs[i]]=1;
	for(rgi i=1;i<=m;++i)
		if(edge[i])
			ret+=w[i];
		else
			ret+=(w[i]<<1);
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>n;
	m=n-1;
	for(rgi i=1;i<=m;++i)
	{
		cin>>u[i]>>v[i]>>w[i];
		nxt[i]=fst[u[i]],fst[u[i]]=i;
		rgi j=i+m;
		u[j]=v[i],v[j]=u[i],w[j]=w[i];
		nxt[j]=fst[u[j]],fst[u[j]]=j;
		pairs[i]=j,pairs[j]=i;
	}
	for(rgi i=1;i<=n;++i)
		cin>>poi[i];
	for(rgi i=1;i<=n;++i)
		if(poi[i])
		{
			memset(book,0,sizeof(book));
			memset(edge,0,sizeof(edge));
			memset(fa,0,sizeof(fa));
			ans=min(ans,bfs(i));
		}
	cout<<ans<<endl;
	return 0;
}

