#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1.1e7 + 10;

int n, id, ans, p[N << 1];
char tmp[N], str[N << 1];

int main() {
	scanf("%s", tmp + 1), n = strlen(tmp + 1);
	for(rgi i = 1; i <= n; ++i) {
		str[(i << 1) - 1] = '$';
		str[i << 1] = tmp[i];
	} str[n << 1 | 1] = '$';
	for(rgi i = 1; i <= (n << 1 | 1); ++i) {
#define MX id + p[id]
		p[i] = MX > i ? std::min(p[(id << 1) - i], MX - i) : 1;
		while(str[i + p[i]] == str[i - p[i]] && i > p[i]) p[i]++;
		if(i + p[i] > MX) id = i;
	}
	for(rgi i = 1; i <= (n << 1 | 1); ++i) ans = std::max(ans, p[i] - 1);
	printf("%d", ans);
	return 0;
}

