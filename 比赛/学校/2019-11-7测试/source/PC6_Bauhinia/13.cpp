#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n,p[1005],s[1005],cnt;
inline void zys(int x)
{
	int xx=x;
	for(rgi i=2;i<=xx;++i)
		if(x%i==0)
		{
			x/=i;
			p[++cnt]=i,s[cnt]=1;
			while(x%i==0)
			{
				x/=i;
				++s[cnt];
			}
		}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("13.in"),fout("13.out");
	cin>>n;
	cout<<n<<"=";
	zys(n);
	for(rgi i=1;i<cnt;++i)
		if(s[i]==1)
			cout<<p[i]<<"*";
		else
			cout<<p[i]<<"^"<<s[i]<<"*";
	if(s[cnt]==1)
		cout<<p[cnt]<<endl;
	else
		cout<<p[cnt]<<"^"<<s[cnt]<<endl;
	return 0;
}

