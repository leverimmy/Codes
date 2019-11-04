#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

double a, b, c, d;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	for(rgi i = -100; i <= 100; ++i)
	{
		double l = i, r = i + 1;
		double x1 = f(l), x2 = f(r);
		if(!x1)
			printf("%.2lf ", l);
		if(x1 * x2 < 0)
		{
			while(r - l >= 0.001)
			{
				double mid = (l + r) / 2.0;
				if(f(mid)*f(r) <= 0)
					l = mid;
				else
					r = mid;
			}
			printf("%.2lf ", r);
		}
	}
	return 0;
}

