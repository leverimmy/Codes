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
#define maxn 1050

using namespace std;

int n, op;
int c[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void add(int x, int y, int val)
{
	for(rgi i = x; i <= n; i += i & -i)
		for(rgi j = y ; j <= n; j += j & -j)
			c[i][j] += val;
}

int query(int x, int y)
{
	int res = 0;
	for(rgi i = x; i; i -= i & -i)
		for(rgi j = y; j; j -= j & -j)
			res += c[i][j];
	return res;
}

int main()
{
	n = read();
	while(scanf("%d", &op))
	{
		if(op == 1)
		{
			int x = read(), y = read(), val = read();
			add(x + 1, y + 1, val);
		}
		else if(op == 2)
		{
			int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
			printf("%d\n", query(x_2 + 1, y_2 + 1) - query(x_2 + 1, y_1) - query(x_1, y_2 + 1) + query(x_1, y_1));
		}
		else if(op == 3)
			break;
	}
	return 0;
}

