#include <iostream>
#include <cstdio>
#include <algorithm>
#define il inline
#define int long long
using namespace std;
int a,b,ans;
int gcd(int p,int q)
{
	if(q==0)
		return p;
	ans+=p/q;
	return gcd(q,p%q);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a>>b;
	if(a<b)
	{
		int t=a;
		a=b;
		b=t;
	}
	int d=gcd(a,b);
	cout<<ans+1<<endl;
	return 0;
}
