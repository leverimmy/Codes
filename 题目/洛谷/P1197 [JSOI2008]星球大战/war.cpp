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
const int N = 4e5 + 10;
const int M = 2e5 + 10;

int n, m, k, tot, cnt;
int p[N], t[N], ans[N];

struct IN
{
	int u, v, t;
	//t -> 倒数第几个被删的 
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
	for(rgi i = 0; i < n; ++i)
		p[i] = i;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		tot--;
	}
}

bool cmp(struct IN a, struct IN b)
{
	return a.t < b.t;
}

void Debug()
{
	for(rgi i = 1; i <= m; ++i)
		cout << in[i].u << " " << in[i].v << " " << in[i].t << endl;
	cout << endl;
}

int main()
{
	n = read(), m = read(), tot = n;
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		in[i].u = read();
		in[i].v = read();
	}
	k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		int val = read();
		t[val] = k - i + 1;
	}
	for(rgi i = 1; i <= m; ++i)
		in[i].t = max(t[in[i].u], t[in[i].v]);
	sort(in + 1, in + m + 1, cmp);
//	Debug();
	for(rgi i = 0, j = 1; i <= k; ++i)
	{
		for(; i == in[j].t; ++j)
			Union(in[j].u, in[j].v);
		//(k - i) -> 已经被炸了几个，用tot减去就是还剩多少个 
		ans[i] = tot - (k - i);
	}
	for(rgi i = k; i >= 0; --i)
		printf("%d\n", ans[i]); 
	return 0;
}

