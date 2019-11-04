#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e4 + 10;

int n, m1, m2, tot;
int ans1, ans2;
int h[N], rev[N], f[N][1010], min_val[N][1010];
	
//lower_bound <
//upper_bound <=

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Discrete() {
	int tmp[N] = {0};
	for(rgi i = 1; i <= n; ++i)	tmp[i] = h[i];
	sort(tmp + 1, tmp + n + 1);
	tot = unique(tmp + 1, tmp + n + 1) - (tmp + 1);
	for(rgi i = 1; i <= n; ++i)
		h[i] = rev[n - i + 1] = lower_bound(tmp + 1, tmp + tot + 1, h[i]) - tmp;
}

int Change(int a, int b) {
	if(b > a)	return m1;
	if(b < a)	return m2;
	return 0;
}

int solve(int a[]) {
//	f[i][j] -> 前i个机器人，改成不下降的，第i个的身高改为j的最小代价
//	f[i][j] = min(f[i - 1][k]) + Change(a[i], j); 
	int res = oo;
	memset(f, 0, sizeof(f)); memset(min_val, 0x3f, sizeof(min_val));
	
	for(rgi i = 1; i <= tot; ++i) {
		f[1][i] = Change(a[1], i);
		min_val[1][i] = min(f[1][i], min_val[1][i - 1]);
	}
	for(rgi i = 2; i <= n; ++i) {
		for(rgi j = 1; j <= tot; ++j) {
			/*int val = oo;
			for(rgi k = 1; k <= j; ++k) {
				val = min(val, f[i - 1][k]);
			}
			f[i][j] = val + Change(a[i], j);*/
			int val = min_val[i - 1][j];
			f[i][j] = val + Change(a[i], j);
			min_val[i][j] = min(f[i][j], min_val[i][j - 1]); 
		}
	}
	for(rgi i = 1; i <= tot; ++i) res = min(res, f[n][i]);
	return res;
}

int main() {
//	freopen("robot.in", "r", stdin);
//	freopen("robot.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(rgi i = 1; i <= n; ++i)	h[i] =read();
	
	Discrete();
	for(rgi i=1;i<=n;++i)
		printf("%d ",h[i]);
	puts("");
	
	ans1 = solve(h);
	ans2 = solve(rev);
	
	printf("%d", min(ans1, ans2));
	
	return 0;
}
/*
8 1 1
769872 896716 881407 908131 857725 868143 838653 874002

15 5 7
10 10 10 10 10 9 2 8 7 6 1000 5 3 4 1

*/
