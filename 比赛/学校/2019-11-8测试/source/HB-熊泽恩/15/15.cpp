#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

char A[N];
int a[N], b[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("15.in", "r", stdin);
	freopen("15.out", "w", stdout);
	while(scanf("%s", A + 1) != EOF) {
		int len = strlen(A + 1);
		int div = read();
		
		for(rgi i = 1; i <= len; ++i)
			a[i] = A[len - i + 1] - '0';
		
		for(rgi i = len; i >= 1; --i) {
			
			if(a[i] < div) {
				a[i - 1] += a[i] * 10;
				b[i] = 0;
			}
			else {
				b[i] = a[i] / div;
				a[i - 1] += a[i] % div * 10;
			}
		}
		
		while(b[len] == 0 && len > 1)	len--;
		
		for(rgi i = len; i >= 1; --i)
			printf("%d", b[i]);
		puts("");
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	return 0;
}
/*
6
2
3593487543987556
9852

*/
