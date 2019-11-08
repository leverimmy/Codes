#include <bits/stdc++.h>
#define rgi register int
#define lowbit(o1) ((o1)&(-(o1)))
using namespace std;
const int maxn=15005;
int n,ans[maxn];
struct poi
{
	int x,y;
}a[maxn];
inline bool cmp(poi p,poi q)
{
	return p.x<q.x;
}
int c[maxn];
inline void change(int i,int x)
{
	for(;i<=n;i+=lowbit(i))
		c[i]+=x;
}
inline int sum(int i)
{
	int ret=0;
	for(;i;i-=lowbit(i))
		ret+=c[i];
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(rgi i=1;i<=n;++i)
	{
		int t=a[i].y;
		++ans[sum(t)];
		change(t,1);
	}
	for(rgi i=0;i<n;++i)
		cout<<ans[i]<<endl;
	return 0;
}

