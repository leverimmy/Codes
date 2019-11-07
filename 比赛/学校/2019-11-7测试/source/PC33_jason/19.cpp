#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
int s,t;
int a,b,c,d;
long long f[10001];
signed main()
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	cin>>s>>t>>a>>b>>c>>d;
	f[1]=1;
	for(int i=2;i<=t;i++)
		f[i]=f[i-1]+f[i-2],f[i]%=(a*b*c*d);
	for(int i=s;i<=t;i++)
		if(f[i]%a&&f[i]%b&&f[i]%c&&f[i]%d)
			printf("%lld ",i);
	return 0;
}