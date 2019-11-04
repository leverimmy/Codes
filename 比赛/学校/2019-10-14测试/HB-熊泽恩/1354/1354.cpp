#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <cmath>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1000 + 10;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int T, n, k, a[N];
int f[10000000];

int main() {
//	freopen("1354.in", "r", stdin);
//	freopen("1354.out", "w", stdout);
	T = read();
	while(T--) {
		f[1] = 1;
		n = read(), k = read();
		
		for(rgi i = 1; i <= n; ++i)	a[i] = read();
		
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = k; j >= a[i]; j -= a[i])
				if(j % a[i] == 0)
					f[j] = (ll)f[j] + f[j / a[i]] % mod, f[j] %= mod;
		printf("%d\n", f[k]);
		memset(f, 0, sizeof(f));
	}
	return 0;
}
/*
2
3 3
1 1 3
3 6
2 3 6

*/
