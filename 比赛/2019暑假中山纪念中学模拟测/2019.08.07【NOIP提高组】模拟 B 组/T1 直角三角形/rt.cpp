#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1500 + 10;

int n, cnt;

struct node
{
	int x, y;
} p[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll dist(int a, int b)
{
	return (ll)(p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y);
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	for(rgi i = 1; i <= n - 2; ++i)
		for(rgi j = i + 1; j <= n - 1; ++j)
			for(rgi k = j + 1; k <= n; ++k)
				if(dist(i, j) + dist(j, k) == dist(i, k) || dist(i, j) + dist(i, k) == dist(j, k) || dist(i, k) + dist(j, k) == dist(i, j))
					cnt++;
	printf("%d", cnt);
	return 0;
}

