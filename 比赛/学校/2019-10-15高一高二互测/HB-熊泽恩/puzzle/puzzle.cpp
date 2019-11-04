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

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 998244353;

int T, type;
ll n;

struct Matrix {
	ll a[2][2];
	void init() {a[0][0] = a[1][1] = 1, a[0][1] = a[1][0] = 0;}
	void clear() {a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;}
	Matrix() {clear();}
};

struct Matrix operator * (struct Matrix rhs, struct Matrix mul) {
	struct Matrix res;
	for(rgi k = 0; k <= 1; ++k)	for(rgi i = 0; i <= 1; ++i)	for(rgi j = 0; j <= 1; ++j)
		res.a[i][j] = (res.a[i][j] + (rhs.a[i][k] * mul.a[k][j]) % mod) % mod;
	return res;
}
	
struct Matrix operator ^ (struct Matrix base, ll power) {
	struct Matrix res; res.init();
	while(power) {
		if(power & 1)
			res = res * base;
		base = base * base;
		power >>= 1;
	}
	return res;
}

ll Fib(ll x) {
	struct Matrix cur, BASE, ans;
	BASE.a[1][0] = BASE.a[1][1] = 1;
	cur.a[0][0] = 0, cur.a[0][1] = cur.a[1][0] = cur.a[1][1] = 1;
	ans = cur ^ (x - 1);
	return (BASE * ans).a[1][0];
}

ll Ted(ll x) {
	struct Matrix cur, BASE, ans;
	BASE.a[1][0] = 1, BASE.a[1][1] = 2;
	cur.a[0][0] = 0, cur.a[0][1] = -3, cur.a[1][0] = 1, cur.a[1][1] = 5;
	ans = cur ^ (x - 1);
	return (((BASE * ans).a[1][0] % mod) + mod) % mod;
}

int main() {
//	freopen("puzzle.in", "r", stdin);
//	freopen("puzzle.out", "w", stdout);
	scanf("%d %d", &T, &type);
	if(type == 1)
		for(rgi i = 1; i <= T; ++i) {
			scanf("%lld", &n);
			printf("%lld\n", Fib(n + 1));
		}
	else
		for(rgi i = 1; i <= T; ++i) {
			scanf("%lld", &n);
			printf("%lld\n", Ted(n + 1));
		}
	return 0;
}
/*
1 1
100000000

*/
