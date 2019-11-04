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
#define maxn 50010

using namespace std;

int n, m;
int c_left[maxn], c_right[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void add_left(int x, int val)
{
	for(; x <= maxn - 1; x += x & -x)
		c_left[x] += val;
}

int query_left(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c_left[x];
	return res;
}

void add_right(int x, int val)
{
	for(; x <= maxn - 1; x += x & -x)
		c_right[x] += val;
}

int query_right(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c_right[x];
	return res;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read(), l = read(), r = read();
		if(op == 1)
		{
			add_left(l, 1);
			add_right(r, 1);
		}
		else if(op == 2)
			printf("%d\n", query_left(r) - query_right(l - 1));
	}
	return 0;
}

