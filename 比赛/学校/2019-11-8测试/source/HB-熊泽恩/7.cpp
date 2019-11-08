#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e6 + 10;

int n, tot;
int vis[N], primes[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void sieve(int x) {
	for(rgi i = 2; i <= x; ++i) {
		if(vis[i])
			continue;
		else {
			primes[++tot] = i;
			for(rgi j = 2; j <= x / i; ++j)
				vis[i * j] = 1;
		}
	}
}

int main() {
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	n = read();
	sieve(n);
	for(rgi i = 1; i <= tot; ++i)
		printf("%d ", primes[i]);
	return 0;
}

