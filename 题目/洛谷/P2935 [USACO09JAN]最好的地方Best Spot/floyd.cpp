#include <iostream>
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 500 + 10;

int n, f, m, min_ans = oo, ans;
int tot[N], like[N], dis[N][N];

int main()
{
	cin >> n >> f >> m;
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			dis[i][j] = oo;
		dis[i][i] = 0;
	}
	for(rgi i = 1; i <= f; ++i)
		cin >> like[i];
	for(rgi i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w;
	}
	for(rgi k = 1; k <= n; ++k)
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= f; ++j)
			tot[i] += dis[i][like[j]];
		if(min_ans > tot[i])
		{
			min_ans = tot[i];
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
