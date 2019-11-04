#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define mod 1000000007
#define maxn 10000005
using namespace std;
typedef long long ll;
ll q[maxn],n,m,k;

ll C(ll a,ll b)
{
	if(a==1) return a;
	return C(b%a,b)*(b-b/a)%b;
}

ll l(ll n,ll m)
{
	ll ans=1;
	while(n&&m)
	{
		if(n%mod<m%mod) return 0;
		ans=ans*q[n%mod]%mod*C(q[(n%mod)-(m%mod)]*q[m%mod]%mod,mod)%mod;
		n/=mod;
		m/=mod;
	}
	return ans;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	q[0]=1;
	for(int i=1;i<maxn;i++)
		q[i]=q[i-1]*i%mod;
	cin>>n>>m>>k;
	n-=k,m-=1;
	printf("%lld\n",l(n,m));
	return 0;
}
