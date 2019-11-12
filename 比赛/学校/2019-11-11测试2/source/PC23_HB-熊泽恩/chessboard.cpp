#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;
const int M = 1e5 + 10;

int n, k, m, tot, now;
int to[M], arr[N], e[N][N];

//to[ver] -> 第ver个版本的棋盘的操作号i

std::vector <int> vec[N][N];

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
			cmd[to[ver]].flag = 1;
			arr[ver] = ++now;
		}
	}
	
	for(rgi i = 0; i <= n - 1; ++i)	for(rgi j = 0; j <= n - 1; ++j)	e[i][j] = 1;
	
	for(rgi i = 1; i <= m; ++i) {
		if(cmd[i].TYPE == 1) {
			for(rgi j = cmd[i].x_1, num1 = 1; j <= cmd[i].x_2; ++j, ++num1)
				for(rgi l = cmd[i].y_1, num2 = 1; l <= cmd[i].y_2; ++l, ++num2)
					if((num1 & 1) == (num2 & 1))
						e[j][l] = cmd[i].color;
		}
		else if(cmd[i].TYPE == 2) {
			if(cmd[i].flag) {
				for(rgi j = 0; j <= n - 1; ++j)	for(rgi l = 0; l <= n - 1; ++l)
					vec[j][l].push_back(e[j][l]);
			}
		}
		else if(cmd[i].TYPE == 3) {
			for(rgi j = 0; j <= n - 1; ++j)	for(rgi l = 0; l <= n - 1; ++l)
				e[j][l] = vec[j][l][arr[cmd[i].ver] - 1];
		}
//		for(rgi j = 0; j <= n - 1; ++j)	{
//			for(rgi l = 0; l <= n - 1; ++l)
//				printf("%d ", e[j][l]);
//			puts("");
//		}
//		puts("");
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
