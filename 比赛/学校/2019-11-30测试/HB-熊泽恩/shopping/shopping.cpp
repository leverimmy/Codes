#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n, tot, A, B;
char str[500 + 10];

struct THING {
	int a, b, vis;
	bool operator < (const struct THING &rhs) const {
		if(a == rhs.a) return b < rhs.b;
		return a > rhs.a;
	}
} w[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("shopping.in", "r", stdin);
//	freopen("shopping.out", "w", stdout);
	scanf("%d %s", &n, str + 1);
	tot = n;
	for(rgi i = 1; i <= n; ++i) scanf("%d %d", &w[i].a, &w[i].b);
	std::sort(w + 1, w + n + 1);
	
	if(str[1] == 'C') {
		A += w[1].a;
		for(rgi i = 2; i <= n - 1; i += 2)
			if(w[i].b > w[i + 1].b) {
				B += w[i].b;
				A += w[i + 1].a;
			}
			else {
				B += w[i + 1].b;
				A += w[i].a;
			}
		printf("%d %d", A, B);
	}
	else {
		for(rgi i = 1; i <= n - 1; i += 2)
			if(w[i].b > w[i + 1].b) {
				B += w[i].b;
				A += w[i + 1].a;
			}
			else {
				B += w[i + 1].b;
				A += w[i].a;
			}
		printf("%d %d", A, B);
	}
	return 0;
}
/*
7
Lagrange
4 1
3 1
2 1
1 1
1 2
1 3
1 4

*/
