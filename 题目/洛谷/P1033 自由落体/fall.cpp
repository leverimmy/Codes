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

const double eps = 0.0001;

double h, s1, v, l, k, n, t1, t2, first, last;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	scanf("%lf %lf %lf %lf %lf %lf", &h, &s1, &v, &l, &k, &n);
	t1 = sqrt(h / 5.0 + eps);
	t2 = sqrt((h - k) / 5.0 + eps);
	first = s1 - v * t2 + l;
	last = s1 - v * t1;
	printf("%d", (int)(min(first, n) - max(last, 0.0) + 0.7111));
	return 0;
}

