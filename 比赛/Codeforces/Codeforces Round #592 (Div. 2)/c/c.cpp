#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

ll n, p, w, d, x, y, g;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

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

bool valid(ll res) {
	return 0 <= res && res <= n;
}

signed main() {
	n = read(), p = read(), w = read(), d = read();
	g = exgcd(w, d, x, y);
	if(p % g == 0) {
		bool flag = 0;
		ll ansx = p / g * x;
		ll ansy = p / g * y;

		ll kx = d / g;
		ll ky = -w / g;
		
		ll tmpx, tmpy;

		for(rgl i = -ansx / kx - 1; i <= n - ansx / kx + 1; ++i) {
			tmpx = ansx + kx * i;
			tmpy = ansy + ky * i;
			if(valid(tmpx) && valid(tmpy) && valid(n - tmpx - tmpy)) {
				flag = 1;
				ansx = tmpx;
				ansy = tmpy;
				break;
			}
		}
		if(flag)
			printf("%lld %lld %lld", ansx, ansy, n - ansx - ansy);
		else
			puts("-1");
	}
	else
		puts("-1");
	return 0;
}
/*
30 60 3 1

1000 1200 3 1

*/
