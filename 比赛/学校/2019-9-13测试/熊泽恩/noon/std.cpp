#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m;

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

struct Fraction
{
	int up, down;
	Fraction(){down = 1;}
	void init(){int g = gcd(up, down); up /= g, down /= g;}
};

bool operator < (struct Fraction a, struct Fraction b)
{
	int cur_l = a.down < 0 ? -1 : 1;
	int cur_r = b.down < 0 ? -1 : 1;
	return (ll)a.up * b.down * cur_l < (ll)a.down * b.up * cur_r;
}

struct Seg_Tree
{
	int lc, rc, len;
	struct Fraction val;
} t[N << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int calc(struct Fraction cur_val, int p)
{
	if(t[p].lc == t[p].rc)
		return cur_val < t[p].val;
	if(!(cur_val < t[p << 1].val))
		return calc(cur_val, p << 1 | 1);
	return t[p].len - t[p << 1].len + calc(cur_val, p << 1);
}

void Pushup(int p)
{
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
	t[p].len = t[p << 1].len + calc(t[p << 1].val, p << 1 | 1);
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].len = 0;
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
//	Pushup(p);
}

void Add(int p, int x, struct Fraction val)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].len = 1;
		t[p].val = val;
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(x <= mid)
		Add(p << 1, x, val);
	else
		Add(p << 1 | 1, x, val);
	Pushup(p);
}

signed main()
{
//	freopen("noon.in", "r", stdin);
//	freopen("noon.out", "w", stdout);
	n = read(), m = read();
	Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i)
	{
		int x = read(), h = read();
		struct Fraction a;	a.up = h, a.down = x;
		a.init();
		Add(1, x, a);
		printf("%d\n", t[1].len);
	}
	return 0;
}
/*
3 4
2 4
3 6
1 1000000
1 1

5 5
1 2
2 5
3 4
4 8
5 20

*/

