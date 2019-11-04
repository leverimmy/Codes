#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cmath>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, q, cnt = 1, siz;
int a[N], belong[N], add[N], sum[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add(int l, int r, int w) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr) {
		for(rgi i = l; i <= r; ++i) {
			a[i] += w;
			sum[posl] += w;
		} return;
	}
	for(rgi i = posl + 1; i <= posr - 1; ++i) {
		add[i] += w;
	}
	for(rgi i = l; i <= posl * siz; ++i) {
		a[i] += w;
		sum[posl] += w;
	}
	for(rgi i = (posr - 1) * siz + 1; i <= r; ++i) {
		a[i] += w;
		sum[posr] += w;
	}
}

il int Query(int l, int r) {
	int posl = belong[l], posr = belong[r], res = 0;
	if(posl == posr) {
		for(rgi i = l; i <= r; ++i) {
			res += a[i];
		}
		return res;
	}
	for(rgi i = posl + 1; i <= posr - 1; ++i) {
		sum[i] += add[i];
		add[i] = 0;
		res += sum[i];
	}
	for(rgi i = l; i <= min(r, posl * siz); ++i) {
		a[i] += add[belong[i]];
		res += a[i];
	}
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i) {
		a[i] += add[belong[i]];
		res += a[i];
	}
	return res;
} 

int main() {
	n = read(), q = read(); siz = sqrt(n);
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		belong[i] = cnt;
		sum[belong[i]] += a[i];
		if(i % siz == 0) cnt++;
	}
	for(rgi i = 1; i <= q; ++i) {
		char op[5]; scanf("%s", op);
		if(op[0] == 'C') {
			int l = read(), r = read(), w = read();
			Add(l, r, w);
		}
		else if(op[0] == 'Q') {
			int l = read(), r = read();
			printf("%d\n", Query(l, r));
		}
	}
	return 0;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4

10 5
11 15 -12 -16 18 -8 -4 -9 16 18
Q 7 8 
C 5 10 -4
Q 6 6 
C 3 4 2
Q 1 4

20 10
21 33 39 30 -26 -37 32 18 -32 36 -28 -34 31 8 18 25 36 6 -34 2
C 5 13 -19
Q 19 20 
C 11 12 17
Q 11 20 
C 14 18 -15
C 7 9 -10
Q 18 20 
Q 19 20 
Q 6 15 
C 7 10 -8

*/
