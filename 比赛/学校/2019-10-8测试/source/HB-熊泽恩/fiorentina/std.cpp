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

int n, p, ans;
int f[450][N] = {1};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), p = read();
	for(rgi i = 1; i * (i + 1) / 2 <= p; ++i) 
		for(rgi j = i; j <= p; ++j) {
			f[i][j] = (f[i - 1][j - i] + f[i][j - i]) % mod;
			if(j >= n + 1) f[i][j] -= f[i - 1][j - (n + 1)];
			if(f[i][j] < 0)	f[i][j] += mod;
			else	f[i][j] %= mod;
		}
	for(rgi i = 1; i * (i + 1) / 2 <= p; ++i) {
		ans += f[i][p];
		ans %= mod;
	}
	printf("%d", ans);
	return 0;
}
/*
233 666

*/
