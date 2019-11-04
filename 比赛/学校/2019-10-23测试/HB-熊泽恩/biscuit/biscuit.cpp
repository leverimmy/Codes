#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 100 + 10;

int n, ans = oo, a[5] = {0, 1, 2, 3, 4};
int tmp1[N << 1][N << 1], tmp2[N << 1][N << 1];
char str[5][N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init(int x) {
	tmp1[1][1] = 1, tmp2[1][1] = 0;
	for(rgi i = 2; i <= n << 1; ++i)
		tmp1[i][1] = !tmp1[i - 1][1], tmp2[i][1] = !tmp2[i - 1][1];
	for(rgi i = 1; i <= n << 1; ++i)	for(rgi j = 2; j <= n << 1; ++j)
		tmp1[i][j] = !tmp1[i][j - 1], tmp2[i][j] = !tmp2[i][j - 1];
}

int solve() {
	int res1 = 0, res2 = 0, state[5] = {0}, e[N << 1][N << 1];
	for(rgi i = 1; i <= 4; ++i)	state[i] = a[i];
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= n; ++j)
		e[i][j] = str[state[1]][i][j] - '0';
	for(rgi i = 1; i <= n; ++i)	for(rgi j = n + 1; j <= n << 1; ++j)
		e[i][j] = str[state[2]][i][j - n] - '0';
	for(rgi i = n + 1; i <= n << 1; ++i)	for(rgi j = 1; j <= n; ++j)
		e[i][j] = str[state[3]][i - n][j] - '0';
	for(rgi i = n + 1; i <= n << 1; ++i)	for(rgi j = n + 1; j <= n << 1; ++j)
		e[i][j] = str[state[4]][i - n][j - n] - '0';
	for(rgi i = 1; i <= n << 1; ++i)	for(rgi j = 1; j <= n << 1; ++j)
		res1 += e[i][j] != tmp1[i][j];
	for(rgi i = 1; i <= n << 1; ++i)	for(rgi j = 1; j <= n << 1; ++j)
		res2 += e[i][j] != tmp2[i][j];
	return std::min(res1, res2);
}

int main() {
//	freopen("biscuit.in", "r", stdin);
//	freopen("biscuit.out", "w", stdout);
	
	n = read(), init(n);
	for(rgi i = 1; i <= n; ++i)	scanf("%s", str[1][i] + 1);
	for(rgi i = 1; i <= n; ++i)	scanf("%s", str[2][i] + 1);
	for(rgi i = 1; i <= n; ++i)	scanf("%s", str[3][i] + 1);
	for(rgi i = 1; i <= n; ++i)	scanf("%s", str[4][i] + 1);
	
	do
		ans = std::min(ans, solve());
	while(std::next_permutation(a + 1, a + 5));
	
	printf("%d", ans);
	return 0;
}
