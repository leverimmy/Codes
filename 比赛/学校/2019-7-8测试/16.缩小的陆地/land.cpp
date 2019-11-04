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

using namespace std;

int T;

const double pi = acos(-1);

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double s(double r)
{
	return pi * r * r / 2.0;
}

int main()
{
	T = read();
	while(T--)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		double r = hypot(x, y);
		double area = s(r);
		int time = ceil(area / 50);
		printf("%d\n", time);
	}
	return 0;
}

