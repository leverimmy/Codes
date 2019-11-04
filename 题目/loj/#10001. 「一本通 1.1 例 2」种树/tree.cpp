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
#define maxn 30010

using namespace std;

int n, m, ans;
int vis[maxn];

struct node
{
	int begin, end, val;
} e[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.end < b.end;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].begin = read();
		e[i].end = read();
		e[i].val = read();
	}
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		int cur = 0;
		for(rgi j = e[i].begin; j <= e[i].end; ++j)
			if(vis[j])
				cur++;
		if(cur >= e[i].val)
			continue;
		for(rgi j = e[i].end; j >= e[i].begin; --j)
		{
			if(!vis[j])
			{
				cur++;
				ans++;
				vis[j] = 1;
				if(cur >= e[i].val)
					break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

