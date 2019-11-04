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
const int N = 2e5 + 10;

int n, q, ans;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x) {
    if(x < 0)    putchar('-'), x = -x;
    if(x > 9)    write(x / 10);
    putchar(x % 10 + 48);
}

int main() {
//	freopen("2735.in", "r", stdin);
//	freopen("2735.out", "w", stdout);
	n = read(), q = read();
	for(rgi i = 0; i < n; ++i)	a[i] = read();
	for(rgi i = 1; i <= q; ++i) {
		ans = 0;
		int x = read(), l = read(), r = read();
		for(rgi j = l; j <= r; ++j)
			ans = max(ans, x ^ a[j]);
		write(ans), putchar('\n');
	}
	return 0;
}
/*
9 8
2 15 4 12 0 6 0 16 12
2 2 5
4 8 8
16 5 8
16 6 8
1 0 5
12 3 4
15 1 1
5 0 4

*/
