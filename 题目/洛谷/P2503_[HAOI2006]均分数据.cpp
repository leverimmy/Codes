#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 50

using namespace std;

int n, m;
double ave, ans;
int a[maxn], p[maxn], s[maxn];

const double k = 0.995;

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

double calc()
{
	double cur = 0;
	for(rgi i = 1; i <= m; ++i)
		cur = cur + square(s[i] - ave);
	return cur / m;
}

void SA()
{
	double T = 5000, tot = ans;
	while(T > 1e-10)
	{
		int pos = rand() % n + 1, tar = rand() % m + 1;
		int cur_group = p[pos];
		s[p[pos]] -= a[pos];
		s[tar] += a[pos];
		p[pos] = tar;
		double cur_ans = calc();
		double delta = cur_ans - ans;
		if(delta < 0)
		{
			tot = cur_ans;
			if(tot < ans)
				ans = tot;
		}
		else if(RAND_MAX * exp(-delta / T) <= rand())
		{
			s[p[pos]] -= a[pos];
			s[cur_group] += a[pos];
			p[pos] = cur_group;
		}
		T *= k;
	}
}

int main()
{
	srand(19260817);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		ave += a[i];
	}
	ave /= m;
	for(rgi i = 1; i <= n; ++i)
	{
		p[i] = rand() % m + 1;
		s[p[i]] += a[i];
	}
	ans = calc();
	for(rgi i = 1; i <= 1100; ++i)
		SA();
	printf("%.2f", sqrt(ans));
	return 0;
}

