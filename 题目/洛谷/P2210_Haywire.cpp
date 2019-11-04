#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 20

using namespace std;

const int inf = 0x3f3f3f3f;
const double k = 0.997;

int n, ans = inf;
int p[maxn], f[maxn][4], g[maxn][maxn];
double T = 5000;

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

il int calc()
{
	int res = 0;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= 3; ++j)
			res += abs(p[i] - p[f[i][j]]);
	return res / 2;
}

il void SA()
{
	T = 5000;
	while(T > 1e-10)
	{
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		swap(p[x], p[y]);
		int temp = calc();
		int delta = temp - ans;
		if(delta < 0)
			ans = temp;
		else if(exp(-delta / T)*RAND_MAX <= rand())
			swap(p[x], p[y]);
		T *= k;
	}
}

int main()
{
	srand(20040301);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i] = i;
		for(rgi j = 1; j <= 3; ++j)
		{
			f[i][j] = read();
			g[i][f[i][j]] = 1;
			g[f[i][j]][i] = 1;
		}
	}
	for(rgi i = 1; i <= 50; ++i)
		SA();
	write(ans);
	return 0;
}

