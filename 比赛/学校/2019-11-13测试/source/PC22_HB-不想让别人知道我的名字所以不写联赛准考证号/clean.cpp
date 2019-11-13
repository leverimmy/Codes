#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=500005;
int n,m,s[maxn],ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	cin>>n>>m;
	for(rgi i=1;i<=m;++i)
	{
		int l,r;
		cin>>l>>r;
		++s[l],--s[r+1];
	}
	for(rgi i=1;i<=n;++i)
	{
		s[i]+=s[i-1];
		if(!s[i])
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}

