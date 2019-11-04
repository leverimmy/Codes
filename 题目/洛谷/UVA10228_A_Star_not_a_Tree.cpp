#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110

using namespace std;

int TASKS, n;
int x[maxn], y[maxn];
double T, ans, ansx, ansy, sx, sy;

const double k = 0.993;
const int inf = 0x3f3f3f3f;

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

il double calc(double a, double b)
{
	double res = 0.0;
	for(rgi i = 1; i <= n; ++i)
		res += hypot(a - x[i], b - y[i]);
	return res;
}

il void SA()
{
	T = 10000000;
	while(T > 1e-10)
	{
		double x = ansx + (rand() * 2 - RAND_MAX) * T;
		double y = ansy + (rand() * 2 - RAND_MAX) * T;
		double temp = calc(x, y);
		double delta = temp - ans;
		if(delta < 0)
		{
			ans = temp;
			ansx = x;
			ansy = y;
		}
		else if(exp(-delta / T)*RAND_MAX > rand())
		{
			ansx = x;
			ansy = y;
		}
		T *= k;
	}
}

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	srand(20040301);
	TASKS = read();
	while(TASKS--)
	{
		n = sx = sy = ansx = ansy = ans = 0;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		n = read();
		for(rgi i = 1; i <= n; ++i)
		{
			x[i] = read();
			y[i] = read();
			sx += x[i];
			sy += y[i];
		}
		ansx = sx / n;
		ansy = sy / n;
		ans = calc(ansx, ansy);
		for(rgi i = 1; i <= 10; ++i)
			SA();
		printf("%.0f\n", calc(ansx, ansy));
		if(TASKS)
			putchar('\n');
	}
	return 0;
}

