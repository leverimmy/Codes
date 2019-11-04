#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n, m, tot;

struct Lef_Tree
{
	int lc, rc, val, dist, p, del;
} t[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Init()
{
	for(rgi i = 1; i <= n; ++i)
		t[i].p = i;
}

int Find(int x)
{
	return x == t[x].p ? x : t[x].p = Find(t[x].p);
}

int Merge(int x, int y)
{
	if(!x || !y)
		return x + y;
	if(t[x].val > t[y].val || (t[x].val == t[y].val && x > y))
		swap(x, y);
	t[x].rc = Merge(t[x].rc, y);
	t[t[x].rc].p = x;
	if(t[t[x].rc].dist > t[t[x].lc].dist)
		swap(t[x].lc, t[x].rc);
	t[x].dist = t[x].rc == 0 ? 0 : t[t[x].rc].dist + 1;
	return x;
}

int Min(int x)
{
	return t[Find(x)].val;
}

void Delete(int x)
{
	t[x].del = 1;
	t[t[x].lc].p = t[x].lc;
	t[t[x].rc].p = t[x].rc;
	t[x].p = Merge(t[x].lc, t[x].rc);
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.ans", "w", stdout);
	n = read(), m = read();
	Init();
	t[0].dist = -1;
	for(rgi i = 1; i <= n; ++i)
		t[i].val = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), y = read();
			if(Find(x) == Find(y) || t[x].del || t[y].del)
				continue;
			Merge(Find(x), Find(y));
		}
		else if(op == 2)
		{
			int x = read();
			if(t[x].del)
				puts("-1");
			else
			{
				printf("%d\n", Min(x));
				Delete(Find(x));
			}
		}
	}
	return 0;
}

