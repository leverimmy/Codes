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

int n,m;
int left[maxn],right[maxn];

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

void add(int A[], int x, int val)
{
	for(; x <= n; x += x & -x)
		A[x] += val;
}

int query(int A[], int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += A[x];
	return res;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int k = read();
		if(k == 1)
		{
			int l = read(), r = read();
			add(left, l, 1);
			add(right, r, 1);
		}
		else if(k == 2)
		{
			int l = read(), r = read();
			printf("%d\n", query(left, r) - query(right, l - 1));
		}
	}
	return 0;
}

