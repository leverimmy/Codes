#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1000 + 10;
const int M = 2e5 + 10;

int n, k, m, tot;
int to[M], nxt[M], e[N][N];

struct COMMAND {
	int TYPE, color;
	int x_1, y_1, x_2, y_2;
	int ver;	bool flag;
} cmd[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	n = read(), k = read(), m = read();
	for(rgi i = 1; i <= m; ++i) {
		char str[10];	scanf("%s", str);
		if(str[0] == 'P') {
			int color = read();
			int x_1 = read(), y_1 = read();
			int x_2 = read(), y_2 = read();
			cmd[i] = COMMAND{1, color, x_1, y_1, x_2, y_2, 0, 0};
		}
		else if(str[0] == 'S') {
			cmd[i] = COMMAND{2, 0, 0, 0, 0, 0, 0, 0};
			to[++tot] = i;
		}
		else if(str[0] == 'L') {
			int ver = read();
			cmd[i] = COMMAND{3, 0, 0, 0, 0, 0, ver, 0};
		}
	}
	
	for(rgi i = 1; i <= m; ++i)	nxt[i] = i + 1;
	
	for(rgi i = m; i >= 1; --i)	if(cmd[i].TYPE == 3)
		nxt[to[cmd[i].ver]] = i, i = to[cmd[i].ver];
		
	for(rgi i = 0; i < n; ++i)	for(rgi j = 0; j < n; ++j)
		e[i][j] = 1;
	
	for(rgi i = 1; i <= m; i = nxt[i]) {
		if(cmd[i].TYPE == 1) {
			for(rgi x = cmd[i].x_1, num1 = 1; x <= cmd[i].x_2; ++x, ++num1)
				for(rgi y = cmd[i].y_1, num2 = 1; y <= cmd[i].y_2; ++y, ++num2)
					if((num1 % 2) == (num2 % 2))	e[x][y] = cmd[i].color;
		}
	}
	
	for(rgi i = 0; i <= n - 1; ++i)	{
		for(rgi j = 0; j <= n - 1; ++j)
			printf("%d ", e[i][j]);
		puts("");
	}
	
	return 0;
}
/*
3 4 7
PAINT 2 0 0 1 1
SAVE
PAINT 3 1 1 2 2
SAVE
PAINT 4 0 2 0 2
LOAD 2
PAINT 4 2 0 2 0

*/
