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

int T, n, m;

bool solve(int a, int b, int cur) {//cur = 1 -> stan; cur = 0 -> ollie
	if(a < b)	swap(a, b);
	if(a == b)	return cur;
	if(a / b >= 2)	return cur;
	return solve(a - b, b, cur ^ 1);
}//1 -> win; 0 -> lose

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	T = read();
	for(rgi i = 1; i <= T; ++i) {
		m = read(), n = read();
		if(solve(m, n, 1))
			puts("Stan wins");
		else
			puts("Ollie wins");
	}
	return 0;
}
/*
2
25 7
24 15

*/
