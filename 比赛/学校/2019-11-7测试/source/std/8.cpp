#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a,b,m;

int main()
{
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	scanf("%lld,%lld,%lld",&a,&b,&m);
	for (ll i = 1; i <= m / a + 1; i++)
		for (ll j = i; j * b + i * a <= m; j++)
			printf("%lld,%lld\n",i,j);
	
	return 0;
}
