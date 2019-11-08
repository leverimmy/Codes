#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 10000 + 10;

char A[N], B[N];
int a[N], b[N], c[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	while(scanf("%s %s", A + 1, B + 1) != EOF) {
		int lenA = strlen(A + 1);
		int lenB = strlen(B + 1);
		
		for(rgi i = 1; i <= lenA; ++i)
			a[i] = A[lenA - i + 1] - '0';
		for(rgi i = 1; i <= lenB; ++i)
			b[i] = B[lenB - i + 1] - '0';
		
		int lenC = lenA + lenB;
		
		for(rgi i = 1; i <= lenA; ++i)
			for(rgi j = 1; j <= lenB; ++j)
				c[i + j - 1] += a[i] * b[j];
		
		for(rgi i = 1; i <= lenC; ++i)
			if(c[i] >= 10) {
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
				if(i == lenC) {
					lenC++;
					break;
				}
			}
		
		while(c[lenC] == 0 && lenC > 1)	lenC--;
		
		for(rgi i = lenC; i >= 1; --i)
			printf("%d", c[i]);
		puts("");
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
	}
	return 0;
}

