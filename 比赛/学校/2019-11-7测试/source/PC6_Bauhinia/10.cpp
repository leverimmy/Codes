#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int a,b,s[1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("10.in"),fout("10.out");
	cin>>a>>b;
	for(rgi i=a;i<=b;++i)
		s[i-a+1]=i;
	int m=(b-a+1)/5,mm=(m<<2)+m;
	for(rgi i=1;i<=m;++i)
	{
		int l=(i-1)*5+1,r=i*5;
		if(!(i&1))
			reverse(s+l,s+r+1);
		for(rgi j=l;j<=r;++j)
			cout<<s[j]<<" ";
		cout<<endl;
	}
	if(b-a+1==mm)
		return 0;
	int l=mm+1;
	if(m&1)
		for(rgi i=b;i>=l;--i)
			cout<<i<<" ";
	else
		for(rgi i=l;i<=b;++i)
			cout<<i<<" ";
	return 0;
}

