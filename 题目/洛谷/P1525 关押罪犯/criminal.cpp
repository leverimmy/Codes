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
const int N = 2e4 + 10;
const int M = 1e5 + 10;

int n, m, flag;
int p[N], Enemy[N];

struct IN
{
	int u, v, w;
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

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
		p[pa] = pb;
}

bool Check(int a, int b)
{
	return Find(a) == Find(b);
}

bool cmp(struct IN a, struct IN b)
{
	return a.w > b.w;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		in[i].u = read();
		in[i].v = read();
		in[i].w = read();
	}
	sort(in + 1, in + m + 1, cmp);
	/*cout << endl;
	for(rgi i = 1; i <= m; ++i)
		cout << in[i].u << " " << in[i].v << " " << in[i].w << endl;
	cout << endl;*/
	for(rgi i = 1; i <= m; ++i)
	{
		int a = in[i].u, b = in[i].v;
		if(Check(a, b))
		{
			flag = 1;
			printf("%d", in[i].w);
			break;
		}
		if(Enemy[a] == 0)
			Enemy[a] = b;
		else
			Union(Enemy[a], b);
		if(Enemy[b] == 0)
			Enemy[b] = a;
		else
			Union(Enemy[b], a);
	}
	if(!flag)
		puts("0");
	return 0;
}

