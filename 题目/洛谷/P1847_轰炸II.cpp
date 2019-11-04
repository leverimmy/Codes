#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long
#define maxn 2050

using namespace std;

int m, n, x, y;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];

int main()
{
	scanf("%d %d", &m, &n);
	for(rgi i = 1; i <= m; ++i)
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
	for(rgi i = 1; i <= n; ++i)
	{
		scanf("%d %d", &x, &y);
		int cnt = 0, last = -1;
		for(rgi j = 1; j <= m; ++j)
		{
			if(x1[j] <= x && x <= x2[j] && y1[j] <= y && y <= y2[j])
			{
				cnt++;
				last = j;
			}
		}
		if(last == -1)
			printf("NO\n");
		else
			printf("YES %d %d\n", cnt, last);
	}
	return 0;
}

