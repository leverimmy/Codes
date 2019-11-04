#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100 + 10;
const int M = 100 + 10;

int n, m;
int f[N][M];
//f[i][j] -> 前i个人项目1做了j个时，项目2已完成个数的最大值

struct People
{
	int x, y;
} p[N];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Binary_Search(int l, int r)
{
	if(l >= r)
		return l;
	int mid = l + r >> 1;
	for(rgi i = 0; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			f[i][j] = -oo;
		f[i][0] = 0;
	}//初始值 
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 0; j <= m; ++j)
			for(rgi k = 0; k <= j; ++k)
			{
				if(k * p[i].x <= mid)
					f[i][j] = max(f[i][j], f[i - 1][j - k] + (mid - k * p[i].x) / p[i].y);
			}
	if(f[n][m] >= m)
		return Binary_Search(l, mid);
	else
		return Binary_Search(mid + 1, r);
}

int main()
{
//	freopen("company.in", "r", stdin);
//	freopen("company.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	printf("%d", Binary_Search(1, 10000));
	return 0;
}

