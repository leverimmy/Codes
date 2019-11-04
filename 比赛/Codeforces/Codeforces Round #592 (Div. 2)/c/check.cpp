#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
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

ll random(ll l, ll r) {
	if(l == r)	return l;
	return (ll)rand() * rand() * rand()% (r - l) + l;
}

signed main() {
	srand(time(0));
	while(1) {
		n = random(1, 10000), p = random(1, 10000), w = random(1, 10000), d = random(1, 10000);
		g = exgcd(w, d, x, y);
		if(p % g == 0) {
			bool flag = 0;
			ll ansx = p / g * x;
			ll ansy = p / g * y;
	
			ll kx = d / g;
			ll ky = -w / g;
			
			ll tmpx, tmpy;
	
			for(rgi i = -ansx / kx - 1; i <= n - ansx / kx + 1; ++i) {
				tmpx = ansx + kx * i;
				tmpy = ansy + ky * i;
				if(valid(tmpx) && valid(tmpy) && valid(n - tmpx - tmpy)) {
					flag = 1;
					ansx = tmpx;
					ansy = tmpy;
					break;
				}
			}
			if(flag) {
//				printf("%lld %lld %lld", ansx, ansy, n - ansx - ansy);
				if(ansx * w + ansy * d == p && valid(ansx) && valid(ansy) && valid(n - ansx - ansy))
					puts("OK");
				else
					printf("%lld %lld %lld %lld", n, p, w, d);
			}
		}
	}
	return 0;
}
/*
30 60 3 1

1000 1200 3 1

*/
