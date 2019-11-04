#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 130;

int d, n, cnt, ans = -oo;
int w[N][N], s[N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	d = read();	n = read();
	for(rgi i = 1; i <= n; ++i)	w[read() + 1][read() + 1] = read();
	for(rgi i = 1; i <= 129; ++i)	for(rgi j = 1; j <= 129; ++j)
		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + w[i][j];
	for(rgi i = 1, cur_x1 = min(i + d, 129), cur_x2 = max(i - d - 1, 0); i <= 129; ++i, cur_x1 = min(i + d, 129), cur_x2 = max(i - d - 1, 0))
		for(rgi j = 1, cur_y1 = min(j + d, 129), cur_y2 = max(j - d - 1, 0); j <= 129; ++j, cur_y1 = min(j + d, 129), cur_y2 = max(j - d - 1, 0)) {
			if(ans < s[cur_x1][cur_y1]
					 - s[cur_x2][cur_y1]
					 - s[cur_x1][cur_y2]
					 + s[cur_x2][cur_y2])
			   ans = s[cur_x1][cur_y1]
					 - s[cur_x2][cur_y1]
					 - s[cur_x1][cur_y2]
					 + s[cur_x2][cur_y2], cnt = 0;
			if(ans == s[cur_x1][cur_y1]
					 - s[cur_x2][cur_y1]
					 - s[cur_x1][cur_y2]
					 + s[cur_x2][cur_y2])
			   cnt++;
		}
	printf("%d %d", cnt, ans);
	return 0;
}
/*
1
11
0 0 10
64 64 10
0 124 5
4 128 5
3 128 1
0 128 4
128 128 10
127 0 10
128 64 10
64 128 9
30 20 10

*/
