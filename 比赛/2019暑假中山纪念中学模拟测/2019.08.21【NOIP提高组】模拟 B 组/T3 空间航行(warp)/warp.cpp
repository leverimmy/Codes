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
#define rgl register ll
#define ld long double
#define il inline

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int N = 100 + 10;

ll n;
double e[N][N];

struct Galaxy
{
	ll x, y, z, r;
} p[N];

il ll read()
{
	rgl f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double dist(ll a, ll b)
{
	if(a == b)
		return 0;
	double res = sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y) + (p[a].z - p[b].z) * (p[a].z - p[b].z)) - p[a].r - p[b].r;
	if(res > 0)
		return res;
	else
		return 0;
}

int main()
{
	freopen("warp.in", "r", stdin);
	freopen("warp.out", "w", stdout);
	while(scanf("%lld", &n) != EOF)
	{
		if(n == -1)
			break;
		for(rgi i = 1; i <= n; ++i)
		{
			p[i].x = read();
			p[i].y = read();
			p[i].z = read();
			p[i].r = read();
		}
		p[0].x = read();
		p[0].y = read();
		p[0].z = read();
		p[0].r = 0;
		p[n + 1].x = read();
		p[n + 1].y = read();
		p[n + 1].z = read();
		p[n + 1].r = 0;
		/*for(rgi i = 0; i <= n + 1; ++i)
		{
			for(rgi j = 0; j <= n + 1; ++j)
				e[i][j] = oo;
			e[i][i] = 0;
		}*/
		for(rgi i = 0; i <= n + 1; ++i)
			for(rgi j = 0; j <= n + 1; ++j)
				e[i][j] = dist(i, j);
		/*for(rgi i = 0; i <= n + 1; ++i)
		{
			for(rgi j = 0; j <= n + 1; ++j)
				cout << e[i][j] << " ";
			cout << endl;
		}*/
		for(rgi k = 0; k <= n + 1; ++k)
			for(rgi i = 0; i <= n + 1; ++i)
				for(rgi j = 0; j <= n + 1; ++j)
					e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
//		cout << e[0][n + 1] * 10 + 0.5;
		printf("%lld\n", (ll)(e[0][n + 1] * 10 + 0.5));
	}
	return 0;
}

