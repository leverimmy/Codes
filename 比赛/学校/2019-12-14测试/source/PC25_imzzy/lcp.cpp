#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define mod 998244353
#define inf 1000000007
using namespace std;

string s;
signed main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,x,y,len;
	cin>>n>>m>>s;
	for(rgi i=1;i<=m;++i)
	{
		cin>>x>>y;
		cout<<(s.substr(x-1)>=s.substr(y-1))<<endl;
	}
	return 0;
}

/*
5 2
abaab
1 3
1 4
*/
