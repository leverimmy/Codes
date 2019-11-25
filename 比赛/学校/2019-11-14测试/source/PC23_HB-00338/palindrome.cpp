#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5000 + 5;

int n, a[N], s[N], f[N][N];
char str[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int work(int l, int r) {
	if(l > r)	return 0;
	if(f[l][r])	return f[l][r];
	
	int mid = l + r >> 1;
	
	if()
		return f[l][r] = work(l, mid) + 1;
	else
		return 0;
}

int main() {
//	freopen("palindrome.in", "r", stdin);
//	freopen("palindrome.out", "w", stdout);
	scanf("%s", str + 1);	n = strlen(str + 1);
	for(rgi len = 1; len <= n; ++len) {
		for(rgi l = 1, r = l + len - 1; r <= n; ++l, r = l + len - 1) {
			f[l][r] = work(l, r);
			a[work(l, r)]++;
		}
	}
	for(rgi i = n; i >= 1; --i)	s[i] = s[i + 1] + a[i];
	for(rgi i = 1; i <= n; ++i)	printf("%d ", s[i]);
	return 0;
}

