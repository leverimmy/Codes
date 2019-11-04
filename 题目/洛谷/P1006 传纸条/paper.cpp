#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N= 50 + 10;

int n, m, e[N][N];
int f[N][N][N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int my_max(int a, int b, int c, int d){return max(max(a, b), max(c, d));}

int dfs(int xa, int ya, int xb, int yb)
{
	if(xa == n && ya == m && xb == n && yb == m)
		return 0;
	if(f[xa][ya][xb][yb] != -1)
		return f[xa][ya][xb][yb];
	int cur = 0;
	if(xa <= n - 1 && xb <= n - 1) if(e[xa + 1][ya] != -1 && e[xb + 1][yb] != -1)
		cur = max(cur, dfs(xa + 1, ya, xb + 1, yb) + e[xa + 1][ya] + e[xb + 1][yb] - e[xa + 1][ya] * (xa + 1 == xb + 1 && ya == yb));
	if(xa <= n - 1 && yb <= m - 1) if(e[xa + 1][ya] != -1 && e[xb][yb + 1] != -1)
		cur = max(cur, dfs(xa + 1, ya, xb, yb + 1) + e[xa + 1][ya] + e[xb][yb + 1] - e[xa + 1][ya] * (xa + 1 == xb && ya == yb + 1));
	if(ya <= m - 1 && xb <= n - 1) if(e[xa][ya + 1] != -1 && e[xb + 1][yb] != -1)
		cur = max(cur, dfs(xa, ya + 1, xb + 1, yb) + e[xa][ya + 1] + e[xb + 1][yb] - e[xa][ya + 1] * (xa == xb + 1 && ya + 1 == yb));
	if(ya <= m - 1 && yb <= m - 1) if(e[xa][ya + 1] != -1 && e[xb][yb + 1] != -1)
		cur = max(cur, dfs(xa, ya + 1, xb, yb + 1) + e[xa][ya + 1] + e[xb][yb + 1] - e[xa][ya + 1] * (xa == xb && ya + 1 == yb + 1));
	return f[xa][ya][xb][yb] = cur;
}

int main()
{
	n = read(), m = read();
	memset(f, -1, sizeof(f));
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			e[i][j] = read();
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			cout << e[i][j] << " ";
		cout << endl;
	}*/
	printf("%d", dfs(1, 1, 1, 1));
	return 0;
}
/*
8 6
0 94 11 25 24 51
15 13 39 67 97 19
76 12 33 99 18 92
35 74 0 95 71 39
33 39 32 37 45 57
71 95 5 71 24 86
8 51 54 74 24 75
70 33 63 29 99 0

*/
