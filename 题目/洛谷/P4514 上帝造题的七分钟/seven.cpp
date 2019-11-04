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
#define maxn 2060
#define maxm 2060

using namespace std;

int n, m;
int c[maxn][maxm], ci[maxn][maxm], cj[maxn][maxm], cij[maxn][maxm];
char cmd[10];

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
		for(rgi j = y; j <= m; j += j & -j)
		{
			c[i][j] += val;
			ci[i][j] += x * val;
			cj[i][j] += y * val;
			cij[i][j] += x * y * val;
		}
}

int query(int x, int y)
{
	int res = 0;
	for(rgi i = x; i; i -= i & -i)
		for(rgi j = y; j; j -= j & -j)
			res += (x + 1) * (y + 1) * c[i][j] - (y + 1) * ci[i][j] - (x + 1) * cj[i][j] + cij[i][j];
	return res;
}

int main()
{
	scanf("%s %d %d", cmd, &n, &m);
	while(scanf("%s", cmd) != EOF)
	{
//		scanf("%s", cmd);
		if(cmd[0] == 'L')
		{
			int a = read(), b = read(), c = read(), d = read(), delta = read();
			add(a, b, delta);
			add(a, d + 1, -delta);
			add(c + 1, b, -delta);
			add(c + 1, d + 1, delta);
		}
		else if(cmd[0] == 'k')
		{
			int a = read(), b = read(), c = read(), d = read();
			printf("%d\n", query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1));
		}
	}
	return 0;
}

