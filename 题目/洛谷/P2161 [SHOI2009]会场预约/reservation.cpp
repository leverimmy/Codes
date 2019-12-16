#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;

int n;

struct INV {
	int l, r;
	bool operator < (const struct INV & rhs) const {
		return r < rhs.l;
	}
} p[N];

std::set <struct INV> s;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		char cmd[5]; int l, r;
		struct INV cur;
		scanf("%s", cmd);
		switch(cmd[0]) {
			case 'A':
				l = read(), r = read();
				cur = INV{l, r};
				printf("%d\n", s.erase(cur));
				s.insert(cur);
				break;
			case 'B':
				printf("%d\n", s.size());
				break;
		}
	}
	return 0;
}
/*
6
A 10 15
A 17 19
A 12 17
A 90 99
A 11 12
B

*/
