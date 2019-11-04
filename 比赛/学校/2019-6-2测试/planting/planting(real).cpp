#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 20

using namespace std;

int n, ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

struct rect
{
	int x1, x2, __y1, y2;
	int flag;
} a[maxn];

struct rect mix(struct rect a, struct rect b)
{
	struct rect ans;
	if(a.x1 > b.x2 || a.__y1 < b.y2 || a.x2 < b.x1 || a.y2 > b.__y1)
		ans.flag = 1;
	else
	{
		ans.x1 = max(a.x1, b.x1);
		ans.x2 = min(a.x2, b.x2);
		ans.__y1 = min(a.__y1, b.__y1);
		ans.y2 = max(a.y2, b.y2);
	}
	return ans;
}

void dfs(int id, struct rect cur, int op)
{
	if(cur.flag == 1 || id > n)
		return;
	ans += (cur.x2 - cur.x1) * (cur.__y1 - cur.y2) * op;
	for(rgi i = id + 1; i <= n; ++i)
		dfs(i, mix(a[i], cur), -op);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i].x1 = read();
		a[i].__y1 = read();
		a[i].x2 = read();
		a[i].y2 = read();
	}
	for(rgi i = 1; i <= n; ++i)
		dfs(i, a[i], 1);
	write(ans);
	return 0;
}

