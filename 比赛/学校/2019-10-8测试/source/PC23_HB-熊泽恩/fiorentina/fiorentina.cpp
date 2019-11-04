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
const int N = 1e5 + 10;

int n, p;
int w[N], f[N] = {1};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("fiorentina.in", "r", stdin);
	freopen("fiorentina.out", "w", stdout);
	n = read(), p = read();
	for(rgi i = 1; i <= n; ++i)	w[i] = i;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = p; j >= w[i]; --j)
			f[j] = (ll)(f[j] + f[j - w[i]]) % mod;
	printf("%d", f[p]);
	return 0;
}

