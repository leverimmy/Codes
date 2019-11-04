#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 30
#define maxm 30
#define max_peanut 410

using namespace std;

int n, m, time, cnt, ans;
int e[maxn][maxm];

struct peanut
{
	int x, y, val;
} p[max_peanut];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct peanut a, struct peanut b)
{
	return a.val > b.val;
}

int dis(struct peanut a, struct peanut b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool check(int a, int b)
{
	if(time >= dis(p[a], p[b]) + p[b].x + 1)
		return 1;
	else
		return 0;
}

int main()
{
	n = read(), m = read(), time = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			e[i][j] = read();
			if(e[i][j])
			{
				cnt++;
				p[cnt].x = i;
				p[cnt].y = j;
				p[cnt].val = e[i][j];
			}
		}
	sort(p + 1, p + cnt + 1, cmp);
	p[0].y = p[1].y;
	for(rgi i = 1; i <= cnt; ++i)
	{
		if(check(i - 1, i))
		{
			ans += p[i].val;
			time -= dis(p[i - 1], p[i]);
			time--;
		}
		else
			break;
	}
	printf("%d", ans);
	return 0;
}

