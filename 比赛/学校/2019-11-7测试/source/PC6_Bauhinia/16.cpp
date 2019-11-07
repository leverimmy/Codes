#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n,s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("16.in"),fout("16.out");
	cin>>n>>s;
	cout<<n<<" ";
	if(s==1)
		return 0;
	int r=(s<<2)-5+n;
	for(rgi i=r;i>=r-s+2;--i)
		cout<<i<<" ";
	cout<<endl;
	int cnt=n,ct=r-s+2;
	for(rgi i=2;i<s;++i)
	{
		++cnt,--ct;
		cout<<cnt<<" ";
		for(rgi j=1;j<=3*(s-2);++j)
			cout<<" ";
		cout<<ct<<endl;
	}
	++cnt,--ct;
	for(rgi i=cnt;i<=ct;++i)
		cout<<i<<" ";
	return 0;
}

