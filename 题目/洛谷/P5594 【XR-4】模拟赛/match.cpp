#include <bits/stdc++.h>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, m, k;
set <int> s[N];

il int read() {
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main() {
	n = read(), m = read(), k = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j) {
		int cur = read();
		s[cur].insert(j);
	}
	for(rgi i = 1; i <= k; ++i)
		printf("%d ", s[i].size());
	return 0;
}
