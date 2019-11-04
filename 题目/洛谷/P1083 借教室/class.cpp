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
#define maxn 1000010

using namespace std;

int n, m, tot;
int a[maxn], ans[maxn];

struct Seg_Tree
{
	int lc, rc, lazy, minn;
} t[maxn << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

void build(int p, int l, int r)
{
	t[p].lc = l;
	t[p].rc = r;
	if(l == r)
	{
		t[p].minn = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].minn = min(t[p << 1].minn, t[p << 1 | 1].minn);
}

void update(int p, int val, int L, int R) //Ñ¯ÎÊ[L,R]
{
	if(t[p].lc == L && R == t[p].rc)
	{
		t[p].minn -= (val + t[p].lazy);
		if(t[p].lc != t[p].rc)
		{
			t[p << 1].lazy += t[p].lazy + val;
			t[p << 1 | 1].lazy += t[p].lazy + val;
		}
		t[p].lazy = 0;
		return;
	}
	t[p << 1].lazy += t[p].lazy;
	t[p << 1 | 1].lazy += t[p].lazy;
	t[p].lazy = 0;
	int mid = (t[p].lc + t[p].rc) >> 1;
	if(R <= mid)
		update(p << 1, val, L, R);
	else if(mid < L)
		update(p << 1 | 1, val, L, R);
	else
	{
		update(p << 1, val, L, mid);
		update(p << 1 | 1, val, mid + 1, R);
	}
	t[p].minn = min(t[p].minn, min(t[p << 1].minn - t[p << 1].lazy, t[p << 1 | 1].minn - t[p << 1 | 1].lazy));
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	build(1, 1, n);
	for(rgi i = 1; i <= m; ++i)
	{
		int d = read(), s = read(), t_1 = read();
		update(1, d, s, t_1);
		if(t[1].minn < 0)
		{
			puts("-1");
			printf("%d", i);
			return 0;
		}
	}
	puts("0");
	return 0;
}

