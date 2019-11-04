#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rgi register int
using namespace std;
const int maxn=1e5+3;
int n,t,a[maxn];
vector<int> b[10003];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>n>>t;
	for(rgi i=1;i<=n;++i)
		cin>>a[i];
	if(n<=1000&&t<=1000)
		for(;t;--t)
		{
			int l,r,p,q;
			cin>>l>>r>>p>>q;
			int ans=0;
			for(rgi i=l;i<=r;++i)
				if(a[i]%p==q)
					++ans;
			cout<<ans<<endl;
		}
	else
	{
		--t;
		int l,r,p,q;
		cin>>l>>r>>p>>q;
		for(rgi i=1;i<=n;++i)
		{
			a[i]%=p;
			b[a[i]].push_back(i);
		}
		int k1=lower_bound(b[q].begin(),b[q].end(),l)-b[q].begin();
		int k2=upper_bound(b[q].begin(),b[q].end(),r)-b[q].begin()-1;
		cout<<k2-k1+1<<endl;
		for(;t;--t)
		{
			cin>>l>>r>>p>>q;
			k1=lower_bound(b[q].begin(),b[q].end(),l)-b[q].begin();
			k2=upper_bound(b[q].begin(),b[q].end(),r)-b[q].begin()-1;
			cout<<k2-k1+1<<endl;
		}
	}
	return 0;
}
