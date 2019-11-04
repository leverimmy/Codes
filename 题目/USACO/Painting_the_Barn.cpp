#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, k, cnt;
int map[2010][2010];

int main()
{
	scanf("%d %d", &n, &k);
	for(rgi i = 1; i <= n; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(rgi x = x1; x <= x2; ++x)
			for(rgi y = y1; y <= y2; ++y)
				map[x][y]++;
	}
	for(rgi i = 1; i <= 1050; ++i)
		for(rgi j = 1; j <= 1050; ++j)
			if(map[i][j] == k)
				cnt++;
	printf("%d\n", cnt);
	return 0;
}

