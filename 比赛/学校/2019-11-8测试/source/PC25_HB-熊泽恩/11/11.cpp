#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int a[N], b[N], c[N];
char A[N], B[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	while(scanf("%s %s", A + 1, B + 1) != EOF) {
		
		int lenA = strlen(A + 1);
		int lenB = strlen(B + 1);
		
		for(rgi i = 1; i <= lenA; ++i)
			a[i] = A[lenA - i + 1] - '0';
		for(rgi i = 1; i <= lenB; ++i)
			b[i] = B[lenB - i + 1] - '0';
//		puts("");
		int lenC = std::max(lenA, lenB);
		for(rgi i = 1; i <= lenC; ++i)
			c[i] = a[i] + b[i];
		for(rgi i = 1; i <= lenC; ++i) {
			if(c[i] >= 10) {
				if(i == lenC)	lenC++;
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
			}
		}
		while(c[lenC] >= 10)	c[lenC + 1] += c[lenC] / 10, lenC++;
		while(c[lenC] == 0 && lenC > 1)	lenC--;
		for(rgi i =lenC; i >= 1; --i)
			printf("%d", c[i]);
		puts("");
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
	}
	return 0;
}

