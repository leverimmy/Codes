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
const int N = 10000 + 10;
const int M = 10000 + 10;

int n, m;
int p[N];

struct edge
{
	int u, v, a, b;
} e[M]; 

//int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

struct Fraction
{
	int up, down;
	void init(){up = 0, down = 0;}
	bool operator < (const struct Fraction& tmp) const {
		return up * tmp.down < down * tmp.up;
	}
	void operator = (const struct Fraction& tmp) {
		up = tmp.up, down = tmp.down;
	}
	Fraction(){init();}
} ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]);}
void Union(int a, int b){p[Find(a)] = Find(b);}
bool Check(int a, int b){return Find(a) == Find(b);}

bool cmp(struct edge a, struct edge b)
{
	return a.a * b.b < b.a * a.b;
}

namespace point_1
{
	void solve()
	{
		ans.up = oo, ans.down = 1;
		for(rgi i = 0; i <= (1 << m) - 1; ++i)//枚举每条边是否被选 
		{
			if(__builtin_popcountl(i) != n - 1)	continue;
			struct Fraction cur_ans;
			for(rgi j = 1; j <= n; ++j)	p[j] = j;
			for(rgi j = 0; j <= m - 1; ++j)
				if((1 << j) & i)
				{
					if(Check(e[j].u, e[j].v))	break;
					Union(e[j].u, e[j].v);
					cur_ans.up += e[j].a;
					cur_ans.down += e[j].b;
				}
			if(cur_ans < ans)
				ans = cur_ans;
		}
		printf("%.6f", (double)ans.up / ans.down);
	}
}

namespace point_2
{
	void solve()
	{
		int tot = 0;  ans.up = 0, ans.down = 0;
		for(rgi i = 1; i <= n; ++i)	p[i] = i;
		sort(e + 1, e + m + 1, cmp);
		for(rgi i = 0; i <= m - 1; ++i)
		{
			if(Check(e[i].u, e[i].v))	continue;
			Union(e[i].u, e[i].v);
			ans.up += e[i].a;
			ans.down += e[i].b;
			
			if(tot == n - 1)
				break;
		}
		printf("%.6f", (double)ans.up / ans.down);
	}
}

int main()
{
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 0; i <= m - 1; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].a = read();
		e[i].b = read();
	}
	if(m <= 20)
	{
		point_1 :: solve();
	}
	else
	{
		point_2 :: solve();
	}
	return 0;
}
/*
3 3
1 2 1 1
2 3 1 3
3 1 1 2

*/

