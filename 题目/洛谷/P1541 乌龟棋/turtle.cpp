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
const int N = 350 + 10;
const int M = 120 + 10;

int n, m;
int a[N], b[N], vis[N];
int f[45][45][45][45];//f[i][j][k][l] -> used: i 1, j 2, k 3, l 4
int tot[5];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int cur1, int cur2, int cur3, int cur4)
{
	if(f[cur1][cur2][cur3][cur4])
		return f[cur1][cur2][cur3][cur4];
	if(cur1 == 0 && cur2 == 0 && cur3 == 0 && cur4 == 0)
		return 0;
	int cur = 1 + cur1 + 2 * cur2 + 3 * cur3 + 4 * cur4, res = -oo;
	if(cur1 >= 1)	res = max(res, dfs(cur1 - 1, cur2, cur3, cur4) + a[cur - 1]);
	if(cur2 >= 1)	res = max(res, dfs(cur1, cur2 - 1, cur3, cur4) + a[cur - 2]);
	if(cur3 >= 1)	res = max(res, dfs(cur1, cur2, cur3 - 1, cur4) + a[cur - 3]);
	if(cur4 >= 1)	res = max(res, dfs(cur1, cur2, cur3, cur4 - 1) + a[cur - 4]);
	return f[cur1][cur2][cur3][cur4] = res;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= m; ++i)
	{
		b[i] = read();
		tot[b[i]]++;
	}
	printf("%d", dfs(tot[1], tot[2], tot[3], tot[4]) + a[n]);
	return 0;
}
/*
9 5
6 10 14 2 8 8 18 5 17
1 3 1 2 1

6 + 10 + 14 + 8 + 18 + 17 = 73

13 4
32 37 75 16 64 33 79 97 22 2 99 100 41
4 2 2 4

32 + 75 + 79 + 99 + 41 = 326
*/

