#include <bits/stdc++.h>
#define int unsigned
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
inline bool prime(int m)
{
	if(m==2)
		return 1;
	for(rgi i=2;i*i<=m;++i)
		if(m%i==0)
			return 0;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("5.in"),fout("5.out");
	cin>>n;
	for(rgi i=n+1;1;++i)
		if(prime(i))
		{
			cout<<i<<endl;
			break;
		}
	return 0;
}

