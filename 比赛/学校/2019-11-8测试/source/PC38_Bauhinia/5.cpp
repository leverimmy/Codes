#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=10005;
const int maxm=100005;
int n,m,cnt,ans,f[maxn];
struct edge
{
	int u,v,w;
}a[maxm];
inline bool cmp(edge p,edge q)
{
	return p.w<q.w;
}
inline int getf(int x)
{
	if(x==f[x])
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	while(cin>>n>>m)
	{
		cnt=0,ans=0;
		for(rgi i=1;i<=n;++i)
			f[i]=i;
		for(rgi i=1;i<=m;++i)
			cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a+1,a+m+1,cmp);
		for(rgi i=1;i<=m;++i)
		{
			int f1=getf(a[i].u),f2=getf(a[i].v);
			if(f1!=f2)
			{
				f[f1]=f2;
				++cnt;
				ans+=a[i].w;
				if(cnt==n-1)
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

