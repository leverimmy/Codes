#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi int

using namespace std;

const int N = 150 + 10;

int n;
int a[N], f[N][N][8];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		f[i][i][a[i]] = 1;
	}
	//f[i][j][k] -> [i, j]ÄÜ·ñºÏ³Ék
	for(rgi len = 1; len <= n - 1; ++len)
		for(rgi l = 1; l <= n - len; ++l)
		{
			int r = l + len;
			for(rgi i = l; i <= r; ++i)
				for(rgi num1 = 0; num1 <= 7; ++num1)
					for(rgi num2 = 0; num2 <= 7; ++num2)
						f[l][r][num1 + num2 >> 1] |= f[l][i][num1] & f[i + 1][r][num2];
		}
	for(rgi i = 0; i <= 7; ++i)
		if(f[1][n][i])
			printf("%d ", i);
	return 0;
}

