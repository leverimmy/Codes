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
const int M = 1e5 + 10;

int n, m;

struct IN {
	int u, v, w;
	bool operator < (const struct IN &rhs) const	{
		return w < rhs.w;
	}
} p[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i) {
		p[i].u = read();
		p[i].v = read();
		p[i].w = read();
	}
	sort(p + 1, p + m + 1);
	return 0;
}

