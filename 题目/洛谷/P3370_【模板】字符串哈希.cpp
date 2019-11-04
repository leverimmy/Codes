#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#define MOD 19260817
#define prime 19260813
#define base 131
#define ll long long

using namespace std;

ll n;
set <ll> se;
ll hash(string s)
{
	ll len=s.length();
	ll ans=0;
	for(ll i=0;i<len;i++)
		ans=(ans*base+s[i])%MOD+prime;
	return ans;
}

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		char s[10010];
		a[i]=hash(s);
	}
	
	cout<<se.size();
	return 0;
}