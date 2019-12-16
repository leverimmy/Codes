#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
using namespace std;
int n,m,pos;
ll ans;
vector<ll> a;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	filein("dance.in"),fileout("dance.out");
	cin>>n>>m;
	for(rgi i=0;i<n;++i)
		a.pb(0ll);
	pos=1;
	while(m--)
	{
		int opt,k,t,siz=a.size();;
		cin>>opt>>k;
		switch(opt)
		{
			case 1:
				for(rgi i=0;i<k;++i)
					a.insert(a.begin(),0ll);
				ans=0ll,pos=1;
				break;
			case 2:
				for(rgi i=0;i<k;++i)
					a.pb(0ll);
				if(ans)
					ans=0ll,pos=siz+1;
				break;
			case 3:
				cin>>t;
				ans=LONG_LONG_MAX,pos=0;
				for(rgi i=0;i<siz;++i)
				{
					a[i]+=k+t*i;
					if(a[i]<ans)
						ans=a[i],pos=i+1;
				}
				break;
		}
		cout<<pos<<" "<<ans<<endl;
	}
	return 0;
}

