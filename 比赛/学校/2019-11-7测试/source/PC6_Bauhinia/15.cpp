#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
struct aa
{
	int x,id;
}a[105];
inline bool cmp(aa p,aa q)
{
	return p.x>q.x;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("15.in"),fout("15.out");
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		a[i].id=i-1;
		cin>>a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1].x<<" "<<a[1].id<<endl;
	return 0;
}

