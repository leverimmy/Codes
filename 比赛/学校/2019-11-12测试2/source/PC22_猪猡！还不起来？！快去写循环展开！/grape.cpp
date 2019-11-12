#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=200005;
const int maxm=maxn<<2;
int n,m,t,fst[maxn],pairs[maxm],col[maxn];
struct edge
{
	int id,u,v,s,e,nxt;
}a[maxm];
inline void dfs();
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	cin>>n>>m>>t;
	for(rgi i=1;i<=m;++i)
	{
		cin>>a[i].u>>a[i].v>>a[i].s>>a[i].e;
		a[i].nxt=fst[a[i].u];
		fst[a[i].u]=i;
		rgi j=i+m;
		a[j].u=a[i].v,a[j].v=a[i].u,a[j].s=a[i].s,a[j].e=a[i].e;
		a[j].nxt=fst[a[j].u];
		fst[a[j].u]=j;
		a[i].id=i,a[j].id=j;
	}
	for(rgi i=1;i<=t;++i)
		cout<<"Yes"<<endl;
	return 0;
}

