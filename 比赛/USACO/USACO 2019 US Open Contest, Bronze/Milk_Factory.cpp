#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

int n, cnt;
int e[110][110];

int main()
{
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			e[i][j] = inf;
	for(int i = 1; i <= n; i++)
		e[i][i] = 0;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		e[v][u] = 1;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(i == j || j == k || k == i)
					continue;
				else
					e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
			}
	for(int i = 1; i <= n; i++)
	{
		int flag = 1;
		for(int j = 1; j <= n; j++)
			if(e[i][j] >= inf)
				flag = 0;
		if(flag)
		{
			printf("%d", i);
			cnt = 1;
		}
	}
	if(!cnt)
		printf("-1");
	return 0;
}

