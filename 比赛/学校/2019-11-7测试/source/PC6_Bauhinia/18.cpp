#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n,m,ans,f[3005];
inline int getf(int x)
{
	if(x==f[x])
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
inline void mer(int x,int y)
{
	int t1=getf(x),t2=getf(y);
	if(t1!=t2)
		f[t1]=t2;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("18.in"),fout("18.out");
	cin>>n>>m;
	for(rgi i=1;i<=n;++i)
		f[i]=i;
	for(;m;--m)
	{
		int x,y;
		cin>>x>>y;
		mer(x,y);
	}
	for(rgi i=1;i<=n;++i)
		if(f[i]==i)
			++ans;
	cout<<ans<<endl;
	return 0;
}

