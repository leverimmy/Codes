#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#define rgi register int
#define il inline

using namespace std;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int T = read();
	while(T--) {
		int a = read(), b = read(), c = read(), d = read(), k = read();
		int ans1 = ceil(a * 1.0 / c), ans2 = ceil(b * 1.0 / d);
		if(ans1 + ans2 > k)	puts("-1");
		else	printf("%d %d\n", ans1, ans2);
	}
	return 0;
}

