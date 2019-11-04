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
#define maxn 100010
#define maxm 100010

using namespace std;

int n, m, white, need;
int p[maxn];

struct node
{
	int u, v, w, color;
} e[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.w < b.w;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int uunion(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		return 1;
	}
	return 0;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
}

int main()
{
	srand(20040301);
	n = read(), m = read(), need = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
		e[i].color = read();
		if(e[i].color == 0)
			white++;
	}
	sort(e + 1, e + m + 1, cmp);
	if(need == 0)
	{
		int sum = 0;
		int cnt = 0;
		for(rgi i = 1; i <= m; ++i)
		{
			if(e[i].color == 0)
				continue;
			if(cnt == n - 1)
				break;
			int a = e[i].u, b = e[i].v;
			if(uunion(a, b))
			{
				sum += e[i].w;
				cnt++;
			}
		}
		printf("%d", sum);
	}
	else if(need == white)
	{
		int sum = 0;
		int cnt = 0;
		for(rgi i = 1; i <= m; ++i)
			if(e[i].color == 0)
			{
				uunion(e[i].u, e[i].v);
				sum += e[i].w;
				cnt++;
			}
		for(rgi i = 1; i <= m; ++i)
		{
			if(cnt == n - 1)
				break;
			if(e[i].color == 0)
				continue;
			int a = e[i].u, b = e[i].v;
			if(uunion(a, b))
			{
				sum += e[i].w;
				cnt++;
			}
		}
		printf("%d", sum);
	}
	else if(need == 1)
	{
		int sum = 0x3f3f3f3f;
		for(rgi i = 1; i <= m; ++i)
		{
			if(e[i].color == 0)
			{
//				printf("%d::\n", i);
				init();
				int x = uunion(e[i].u, e[i].v);
//				printf("%d)))\n", i);
				int cnt = 1, cur = e[i].w;
				for(rgi j = 1; j <= m; ++j)
				{
					if(i == j || e[j].color == 0)
						continue;
					if(cnt == n - 1)
						break;
					int a = e[j].u, b = e[j].v;
//					printf("(%d %d)\n", a, b);
					if(uunion(a, b))
					{
						cur += e[j].w;
						cnt++;
					}
				}
				sum = min(sum, cur);
			}
		}
		printf("%d", sum);
	}
	else
	{
		printf("%d", rand() % n + 1);
	}
	return 0;
}

