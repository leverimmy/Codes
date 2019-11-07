#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;

bool check(ll x)
{
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	scanf("%lld",&n);
	while (!check(n + 1))
		n++;
	printf("%lld\n",n + 1);
	
	return 0;
}
