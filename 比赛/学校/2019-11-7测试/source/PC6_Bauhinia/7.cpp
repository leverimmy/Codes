#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
bool a[22][22];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("7.in"),fout("7.out");
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		int s=0;
		for(rgi j=1;j<=n;++j)
		{
			cin>>a[i][j];
			s+=a[i][j];
		}
		if(s>(n>>1))
			cout<<i<<endl;
	}
	return 0;
}

