#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline

int T;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("friend.in", "r", stdin);
//	freopen("friend.out", "w", stdout);
	T = read();
	while(T--)	puts("0!");
	return 0;
}
