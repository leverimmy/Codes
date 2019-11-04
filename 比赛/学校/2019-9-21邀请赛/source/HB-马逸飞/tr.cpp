#include <iostream>
#include <utility>
#include <queue>
#define il inline
#define rgi register int
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int inf=0x3f3f3f3f;
int n,m,u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm],indx=-1;
int dis[maxn];
bool book[maxn];
priority_queue<pii,vector<pii>,greater<pii> > que;
inline void addedge(int p,int q,int r)
{
	u[++indx]=p,v[indx]=q,w[indx]=r;
	nxt[indx]=fst[p];
	fst[p]=indx;
}
int main()
{
	ios::sync_with_stdio(false);
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(rgi i=2;i<=n;++i)
		dis[i]=inf;
	for(rgi i=1;i<=m;++i)
	{
		int p,q,r;
		cin>>p>>q>>r;
		addedge(p,q,r),addedge(q,p,r);
	}
	que.push(mkp(inf,1));
	book[1]=1;
	while(!que.empty())
	{
		int x=que.front().fi,val=que.front().se;
		for(rgi i=fst[x];i;i=nxt[i])
		{
			int y=v[i];
			if(book[y])
				continue;
			book[y]=1;
			if(dis[y]>=)
		}
	}
	return 0;
}
