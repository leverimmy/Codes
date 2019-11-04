#include <iostream>
#include <algorithm>
#define rgi register int
using namespace std;
int n,m,f[100005],indx,cnt,ans;
int u[200005],v[200005],w[200005];
int fst[100005],nxt[200005],s[100005];
bool book[100005];
struct edge
{
	int u,v,w;
}a[100005];
inline bool cmp(edge p,edge q)
{
	return p.w<=q.w;
}
inline void addedge(int p,int q,int r)
{
	u[++indx]=p,v[indx]=q,w[indx]=r;
	nxt[indx]=fst[p];
	fst[p]=indx;
}
inline void dfs(int x,int val)
{
	book[x]=1;
	s[x]=val;
	for(rgi i=fst[x];i;i=nxt[i])
		if(!book[v[i]])
			dfs(v[i],max(val,w[i]));
}
inline int getf(int x)
{
	if(x==f[x])
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(rgi i=1;i<=n;++i)
		f[i]=i;
	for(rgi i=1;i<=m;++i)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(rgi i=1;i<=m;++i)
	{
		int f1=getf(a[i].u),f2=getf(a[i].v);
		if(f1==f2)
			continue;
		f[f1]=f2;
		addedge(a[i].u,a[i].v,a[i].w),addedge(a[i].v,a[i].u,a[i].w);
		++cnt;
		if(cnt==n-1)
			break;
	}
	dfs(1,0);
	for(rgi i=2;i<=n;++i)
		ans+=s[i];
	cout<<ans<<endl;
	return 0;
}
