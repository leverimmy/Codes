#include <bits/stdc++.h>
#define il inline
#define rgi register int
#define stack _stack
using namespace std;
const int maxn=100005;
const int maxm=1000005;
int n,m,u[maxm],v[maxm],fst[maxn],nxt[maxm],cnt;
int stack[maxn],c[maxn],top,num,dfn[maxn],low[maxn];
bool ins[maxn];
int ind[maxn],oud[maxn],noi,noo;
void tarjan(int x)
{
	dfn[x]=low[x]=++num;
	stack[++top]=x,ins[x]=1;
	for(rgi i=fst[x];i;i=nxt[i])
		if(!dfn[v[i]])
		{
			tarjan(v[i]);
			low[x]=min(low[x],low[v[i]]);
		}
		else if(ins[v[i]])
			low[x]=min(low[x],dfn[v[i]]);
	if(dfn[x]==low[x])
	{
		++cnt;
		int y;
		do
		{
			y=stack[top--],ins[y]=0;
			c[y]=cnt;
		}while(x!=y);
	}
}
signed main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	while(cin>>n>>m)
	{
		memset(fst,0,sizeof(fst));
		memset(nxt,0,sizeof(nxt));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		cnt=0,top=0;
		for(rgi i=1;i<=m;++i)
		{
			cin>>u[i]>>v[i];
			nxt[i]=fst[u[i]];
			fst[u[i]]=i;
		}
		for(rgi i=1;i<=n;++i)
			if(!dfn[i])
				tarjan(i);
		cout<<cnt<<endl;
	}
	return 0;
}

