#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 10010
#define max_size 2010
#define max_len 7
#define max_num 6

using namespace std;

int T, n, x, y, cur_id, cnt;
int ans[maxn];
int e[max_size][max_size];

struct Number
{
	int id, val;
} p[max_num];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct Number a, struct Number b)
{
	if(a.val == b.val)
		return a.id < b.id;
	return a.val < b.val;
}

void place(int x, int y)
{
	sort(p + 1, p + 6, cmp);
	bool vis[6] = {0};
	vis[e[x - 1][y]] = vis[e[x][y - 1]] = vis[e[x - 1][y - 1]] = 1;
	vis[e[x + 1][y]] = vis[e[x][y + 1]] = vis[e[x + 1][y + 1]] = 1;
	for(rgi i = 1; i <= 5; ++i)
	{
		if(!vis[p[i].id])
		{
			ans[cur_id] = e[x][y] = p[i].id;
			p[i].val++;
			break;
		}
	}
}

void init()
{
	cur_id = cnt = 1;
	x = y = 250;
	e[x][y] = 1;
	p[1].val++;
	ans[1] = 1;
	for(rgi i = 1; i <= 5; ++i)
		p[i].id = i;
	while(cur_id <= 10005)
	{
		x++, y++;
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			x--;
			place(x, y);
		}
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			x--, y--;
			place(x, y);
		}
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			y--;
			place(x, y);
		}
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			x++;
			place(x, y);
		}
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			x++, y++;
			place(x, y);
		}
		for(rgi i = 1; i <= cnt; ++i)
		{
			cur_id++;
			y++;
			place(x, y);
		}
		cnt++;
	}
}

int main()
{
	init();
	T = read();
	for(; T; T--)
	{
		n = read();
		printf("%d\n", ans[n]);
	}
	return 0;
}

