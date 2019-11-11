#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 8000 + 10;

int n, flag, cnt[N];
char A[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("reference.in", "r", stdin);
	freopen("reference.out", "w", stdout);
	n = read();
	scanf("%s", A + 1);
	for(rgi i = 1; i <= n; ++i) cnt[A[i] - 'a' + 1]++;
	
	for(rgi i = 1; i <= 26; ++i)	flag += cnt[i] & 1;
	
//	if(flag >= 2)
		puts("Impossible");
//	else {
//		for(rgi i = 1; i <= n; ++i)
//	}
	return 0;
}

