#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
double n,x;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("11.in"),fout("11.out");
	while(1)
	{
		x=0;
		cin>>n;
		if(n==0.00)
			break;
		rgi i;
		for(i=2;x<n;++i)
			x+=(1.00/i);
		i-=2;
		cout<<i<<" card(s)"<<endl;
	}
	return 0;
}

