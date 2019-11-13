#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=5005,maxm=1000005;
int n,m,a[maxn],s[maxn],d[maxn],ans;
struct doit
{
	int l,r,val;
}b[maxm];
inline bool cmp(doit p,doit q)
{
	return p.val>q.val;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(rgi i=1;i<=n;++i)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(rgi i=1;i<=m;++i)
	{
		cin>>b[i].l>>b[i].r;
		if(b[i].l>b[i].r)
			swap(b[i].l,b[i].r);
		b[i].val=s[b[i].r]-s[b[i].l-1];
	}
	sort(b+1,b+m+1,cmp);
	for(rgi i=1;i<=m;++i)
		
	return 0;
}

