#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n,cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("12.in"),fout("12.out");
	cin>>n;
	for(rgi i=1;i<=n;++i)
		if(n%i==0)
			++cnt;
	cout<<cnt<<endl;
	return 0;
}

