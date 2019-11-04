#include <cstdio>
#include <algorithm>
#include <iostream>
#define ll long long

using namespace std;

ll x, y, m, n, l;
ll a, b, c, ans1, ans2, g, mod;

ll exgcd(ll a, ll b, ll &X, ll &Y)
{
	if(b == 0)
	{
		X = 1;
		Y = 0;
		return a;
	}
	ll r = exgcd(b, a % b, X, Y);
	ll t = X;
	X = Y;
	Y = t - a / b * Y;
	return r;
}

int main()
{
	cin >> x >> y >> m >> n >> l;
	a = n - m, b = l, c = x - y;
	g = exgcd(a, b, ans1, ans2), mod = l / g > 0 ? l / g : -l / g;
//	cout << g << " " << ans1 << " " << ans2 << endl;
	if(c % g == 0)
		cout << ((ans1 * c / g) % mod + mod) % mod;
	else
		cout << "Impossible";
	return 0;
}
/*
1 2 3 4 5

*/
