#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int a[N];
char A[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("13.in", "r", stdin);
	freopen("13.out", "w", stdout);
	while(scanf("%s", A + 1) != EOF) {
		int len = strlen(A + 1);
		int mul = read();
		
		for(rgi i = 1; i <= len; ++i)
			a[i] = A[len - i + 1] - '0';
		
		for(rgi i = 1; i <= len; ++i)
			a[i] *= mul;
		
		for(rgi i = 1; i < len; ++i)
			if(a[i] >= 10) {
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
			}
		
		while(a[len] == 0 && len > 1)	len--;
		
		for(rgi i = len; i >= 1; --i)
			printf("%d", a[i]);
		puts("");
	}
	return 0;
}

