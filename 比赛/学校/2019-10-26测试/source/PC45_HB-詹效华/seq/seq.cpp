#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int ans=1;
int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	ans+=x/y;
	return gcd(y,x%y);
}
signed main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int x,y;
	scanf("%lld%lld",&x,&y);
	gcd(x,y);
	printf("%lld",ans);
	return 0;
}