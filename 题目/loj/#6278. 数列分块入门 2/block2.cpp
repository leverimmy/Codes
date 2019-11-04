#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline

int n, siz;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Modify(int l, int r, int c) {
	
}

int Query(int l, int r, int c) {
	
}

int main() {
	n = read(); siz = sqrt(n);
	for(rgi i = 1; i <= n; ++i)	{
		a[i] = read();
		belong[i] = tot;
		tot += i % siz == 0;
	}
	for(rgi i = 1; i <= n; ++i) {
		int opt = read(), l = read(), r = read(), c = read();
		if(opt == 0) {
			Modify(l, r, c);
		}
		else if(opt == 1) {
			printf("%d\n", Query(l, r, c * c));
		}
	}
	return 0;
}
