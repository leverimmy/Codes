#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int l, r, e[10][110];

void dfs(int x, int y, int val, int flag) { //1 -> right, -1 -> left
	if(val > r)
		return;
	e[x][y] = val;
	if(y == 5 && flag == 1)
		dfs(x + 1, 5, val + 1, -flag);
	else if(y == 1 && flag == -1)
		dfs(x + 1, 1, val + 1, -flag);
	else
		dfs(x, y + flag, val + 1, flag);
}

int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	std::cin >> l >> r;
	dfs(1, 1, l, 1);
	for(rgi i = 1; i <= (r - l + 1) / 5 + 1; ++i)	{
		for(rgi j = 1; j <= 5; ++j)	if(e[i][j])
			printf("%d ", e[i][j]);
		puts("");
	}
	return 0;
}

