#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;
const int M = 100000 + 10;

int n, m, ans, flag, cnt;
int p[N];

struct IN
{
	int u, v, t;
}in[M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

bool Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		return 1;
	}
	return 0;
}

bool cmp(struct IN a, struct IN b)
{
	return a.t < b.t;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		in[i].u = read();
		in[i].v = read();
		in[i].t = read();
	}
	sort(in + 1, in + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		int cur_u = in[i].u, cur_v = in[i].v, cur_t = in[i].t;
		if(Union(cur_u, cur_v))
			cnt++;
		if(cnt == n - 1)
		{
			flag = 1;
			ans = cur_t;
			break;
		}
	}
	if(flag)
		printf("%d", ans);
	else
		puts("-1");
	return 0;
}

