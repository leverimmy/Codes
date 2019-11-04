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

int T;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("boynextdoor.in", "r", stdin);
	freopen("boynextdoor.out", "w", stdout);
	T = read();
	while(T--) {
		int a = read(), b = read();
		if(a && b)	printf("%d\n", a - b - 2);
		else		printf("%d\n", a - b);
	}
	return 0;
}

