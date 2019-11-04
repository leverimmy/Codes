#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010

using namespace std;

int n, m, d0, s1, s2, w;
int score, miss_time, max_time;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

struct obj
{
	int x, l, r, t, v;
	int p, a, b;
	int flag = 0;
} item[maxn];

struct cmd
{
	int p;
	int s, t;
} fix[maxn];

bool cmp(struct obj a, struct obj b)
{
	return a.t < b.t;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		item[i].x = read();
		item[i].l = read();
		item[i].r = read();
		item[i].t = read();
		item[i].v = read();
		time_line[item[i].t] = i;
	}
	for(rgi i = 1; i <= m; ++i)
	{
		fix[i].p = read();
		fix[i].s = read();
		fix[i].t = read();
	}
	d0 = read();
	s1 = read(), s2 = read(), w = read();
	sort(item + 1, item + n + 1, cmp);
	for(rgi i = 1;; i++)
	{
		max_time = i;
		if(time_line[i] == 0)
			continue;
		if(miss_time > w)
			break;
	}
	write(score);
	putchar('\n');
	write(max_time);
	return 0;
}

