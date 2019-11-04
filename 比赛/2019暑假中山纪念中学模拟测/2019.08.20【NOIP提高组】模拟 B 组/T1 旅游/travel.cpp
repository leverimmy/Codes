#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const ll oo = 0x3f3f3f3f;
const ll N = 1000 + 10;
const ll M = 1000 + 10;

ll n, m, max_val = -oo, ans = -oo;
ll siz[N];
ll A[N][M], B[N][M], f[N][M];

struct Point
{
	ll x, y;
};

vector <struct Point> vec[N];

il ll read()
{
	rgl f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll dfs(ll cur_x, ll cur_y)
{
	if(f[cur_x][cur_y] != -1)
		return f[cur_x][cur_y];
	ll res = 0;
	for(rgl i = A[cur_x][cur_y] + 1; i <= max_val; ++i)
	{
		if(siz[i])
			for(rgl j = 0; j < siz[i]; ++j)
				res = max(res, dfs(vec[i][j].x, vec[i][j].y) + abs(cur_x - vec[i][j].x) + abs(cur_y - vec[i][j].y));
	}
	f[cur_x][cur_y] = res + B[cur_x][cur_y];
	return f[cur_x][cur_y];
}

int main()
{
	n = read(), m = read();
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = 1; j <= m; ++j)
			A[i][j] = read();
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = 1; j <= m; ++j)
			B[i][j] = read();
	for(rgl i = 1; i <= n; ++i)
	{
		for(rgl j = 1; j <= m; ++j)
		{
			if(A[i][j] || B[i][j])
			{
				struct Point tmp;
				tmp.x = i, tmp.y = j;
				vec[A[i][j]].push_back(tmp);
				max_val = max(max_val, A[i][j]);
				siz[A[i][j]]++;
			}
		}
	}
	memset(f, -1, sizeof(f));
	for(rgl i = 0; i <= max_val; ++i)
	{
		if(siz[i])
			for(rgl j = 0; j < siz[i]; ++j)
				ans = max(ans, dfs(vec[i][j].x, vec[i][j].y));
	}
	printf("%lld", ans);
	return 0;
}

