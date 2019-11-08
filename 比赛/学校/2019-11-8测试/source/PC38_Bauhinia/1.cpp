#include <bits/stdc++.h>
#define int long long
#define rgi register int
using namespace std;
int a,b,c;
inline int ksm(int p,int q,int r)
{
	if(!q)
		return 1;
	if(q==1)
		return p%r;
	int ans=ksm(p,q>>1,r);
	if(q&1)
		return ans*p%r*ans%r;
	else
		return ans*ans%r;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>a>>b>>c;
	cout<<ksm(a,b,c)<<endl;
	return 0;
}
