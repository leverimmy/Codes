#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010

using namespace std;

int n, m, sx, sy;
double ans = 1e18, T, ansx, ansy;
int x[maxn], y[maxn], w[maxn];
const double k = 0.992;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

double square(double x)
{
	return x * x;
}

double calc(double _x, double _y)
{
	double cur = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		double dx = _x - x[i], dy = _y - y[i];
		cur += sqrt(dx * dx + dy * dy) * w[i];
	}
	return cur;
}

void SA()
{
	double x = ansx, y = ansy;
	T = 2010;
	while(T > 1e-14)
	{
		double cur_x = x + ((rand() << 1) - RAND_MAX) * T;
		double cur_y = y + ((rand() << 1) - RAND_MAX) * T;
		double cur_ans = calc(cur_x, cur_y);
		double delta = cur_ans - ans;
		if(delta < 0)
		{
			x = cur_x;
			y = cur_y;
			ansx = x;
			ansy = y;
			ans = cur_ans;
		}
		else if(RAND_MAX * exp(-delta / T) > rand())
		{
			x = cur_x;
			y = cur_y;
		}
		T *= k;
	}
}

int main()
{
	srand(20040301);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		x[i] = read();
		y[i] = read();
		w[i] = read();
		sx += x[i];
		sy += y[i];
	}
	ansx = (double)sx / n;
	ansy = (double)sy / n;
	SA();
	SA();
	SA();
	SA();
	SA();
	printf("%.3f %.3f", ansx, ansy);
	return 0;
}

