#include<bits/stdc++.h>
using namespace std;
long long n,m,p,k;
long long quickpow(long long bas,long long num)
{
	long long ret=1;
	while(num)
	{
		if(num&1)
		{
			ret*=bas,
			ret%=p;
		}
		bas*=bas,
		bas%=p,
		num>>=1;
	}
	return ret;
}
long long C(long long n,long long m)
{
	if(m>n)
		return 0;
	long long a=1,b=1;
	for(long long i=n-m+1;i<=n;i++)
		a=a*i%p;
	for(long long i=2;i<=m;i++)
		b=b*i%p;
	return a*quickpow(b,p-2)%p;
}
long long lucas(long long n,long long m)
{
	if(!m)
		return 1;
	else
		return (C(n%p,m%p)*lucas(n/p,m/p))%p;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	p=1e9+7;
	cin>>n>>m>>k;
	cout<<lucas(n-k,m-1)<<endl;
	return 0;
}
