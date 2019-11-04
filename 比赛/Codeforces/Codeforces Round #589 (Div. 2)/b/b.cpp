#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline
#define int long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1000 + 10;

ll h, w, ans;
ll r[N], c[N], a[N][N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll ksm(ll base, ll power, ll mod) {
	ll res = 1 % mod;
	while(power) {
		if(power & 1)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

signed main() {
	h = read(), w = read();
	memset(a, -1, sizeof(a));
	for(rgi i = 1; i <= h; ++i) {
		r[i] = read();
		for(rgi j = 1; j <= r[i]; ++j) {
			if(a[i][j] == 0) {
				puts("0");
				return 0;
			}
			a[i][j] = 1;
		}
		if(a[i][r[i] + 1] == 1) {
			puts("0");
			return 0;
		}
		a[i][r[i] + 1] = 0;
	}
	for(rgi i = 1; i <= w; ++i) { 
		c[i] = read();
		for(rgi j = 1; j <= c[i]; ++j) {
			if(a[j][i] == 0){
				puts("0");
				return 0;
			}
			a[j][i] = 1;
		}
		if(a[c[i] + 1][i] == 1) {
			puts("0");
			return 0;
		}
		a[c[i] + 1][i] = 0;
	}
	for(rgi i = 1; i <= h; ++i) {
		for(rgi j = 1; j <= w; ++j)
			ans += (a[i][j] == -1);
	}
	/*puts("");
	for(rgi i = 1; i <= h; ++i) {
		for(rgi j = 1; j <= w ;++j)
			printf("%d ", a[i][j]);
		puts(""); 
	}*/
	//if(ans == 0) puts("0");
	//else 
	printf("%lld", ksm(2, ans, mod));
	return 0;
}

