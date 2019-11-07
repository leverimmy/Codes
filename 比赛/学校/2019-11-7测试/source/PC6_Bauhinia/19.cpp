#include <bits/stdc++.h>
#define int long long
#define rgi register long long
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int s,t,f[10005],cnt,ans[10005];
int a,b,c,d;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("19.in"),fout("19.out");
	f[1]=1,f[2]=1;
	cin>>s>>t>>a>>b>>c>>d;
	int mod=a*b*c*d;
	for(rgi i=3;i<=t;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(rgi i=s;i<=t;++i)
		if(f[i]%a!=0&&f[i]%b!=0&&f[i]%c!=0&&f[i]%d!=0)
			ans[++cnt]=i;
	for(rgi i=1;i<=cnt;++i)
		cout<<ans[i]<<" ";
	return 0;
}

