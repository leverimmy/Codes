#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 20 + 10;

int n, m, ans = -oo;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 0; i < n; ++i)	a[i] = read();
	for(rgi state = 0; state <= (1 << n) - 1; ++state) if(__builtin_popcountl(state) == n - m) {
		bitset <2010> bs;	bs[0] = 1;
		for(rgi i = 0; i < n; ++i) if(state & (1 << i))
			bs |= bs << a[i];
		int cur = bs.count();
		if(ans < cur)	ans = cur;
	}
	printf("%d", ans - 1);
	return 0;
}

