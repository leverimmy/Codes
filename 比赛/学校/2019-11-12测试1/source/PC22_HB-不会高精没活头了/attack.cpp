#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,ll>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=100005,maxm=maxn<<1;
int n,m,a[maxn],pairs[maxm],fa[maxn];
int u[maxm],v[maxm],fst[maxn],nxt[maxm];
bool book[maxn];
pii bfs(int s)
{
	ll ret=a[s];
	int pos=s;
	queue<pii> que;
	que.push(s,ret);
	book[s]=1;
	while(!que.empty())
	{
		int x=que.front().fi;
		ll val=que.front().se;
		if(val>ret)
		{
			ret=val;
			pos=x;
		}
		que.pop();
		for(rgi i=fst[x];i;i=nxt[i])
		{
			int y=v[i];
			if(book[y])
				continue;
			book[y]=1;
			fa[y]=i;
			que.push(mkp(y,val+(ll)a[y]));
		}
	}
	return mkp(pos,ret);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	m=n-1;
	for(rgi i=1;i<=m;++i)
	{
		cin>>u[i]>>v[i];
		nxt[i]=fst[u[i]];
		fst[u[i]]=i;
		rgi j=i+m;
		nxt[j]=fst[u[j]];
		fst[u[j]]=j;
		pairs[i]=j,pairs[j]=i;
	}
	memset(book,0,sizeof(book));
	pii b1=bfs(1);
	book[1]=1;
	for(rgi i=)
	return 0;
}

