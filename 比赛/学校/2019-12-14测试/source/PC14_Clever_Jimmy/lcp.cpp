#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

#define DEBUG 0

const int N = 1e5 + 10;
const int BASE = 137;
const int MOD = 1e9 + 7;

int n, m;
char str[N];

std::string s[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Hash() {
	hash_front[0] = 1;
	for(rgi i = 1; i <= n; ++i) hash_front[i] = hash_front[i - 1] * BASE % MOD;
	hash_back[n + 1] = 1;
	for(rgi i = n; i >= 1; --i) hash_back[i] = hash_back[i + 1] * BASE % MOD; 
}

int main() {
//	freopen("lcp.in", "r", stdin);
//	freopen("lcp.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", str + 1);
	Get_Hash();
	for(rgi i = 1; i <= m; ++i) {
		int a = read(), b = read();
		
	}
	return 0;
}

