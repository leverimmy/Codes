#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int L[401], R[401], n, m, block[maxn], s;
double d, a[maxn], SUM[401], ADD[401], quad[401];

double square(double val)
{
	return val * val;
}

void add(int l, int r, double val)
{
	int lx = block[l], rx = block[r];
	if(lx == rx)
	{
		for(rgi i = l; i <= r; i++)
		{
			quad[lx] += 2 * a[i] * val + square(val);
			a[i] += val;
			SUM[lx] += val;
		}
		return;
	}
	for(rgi i = l; i <= R[lx]; i++)
	{
		quad[lx] += 2 * a[i] * val + square(val);
		a[i] += val;
		SUM[lx] += val;
	}
	for(rgi i = L[rx]; i <= r; i++)
	{
		quad[rx] += 2 * a[i] * val + square(val);
		a[i] += val;
		SUM[rx] += val;
	}
	for(rgi i = lx + 1; i <= rx - 1; i++)
		ADD[i] += val;
}
double average(int l, int r)
{
	int lx = block[l], rx = block[r], len = r - l + 1;
	double ans = 0;
	if(lx == rx)
	{
		for(rgi i = l; i <= r; i++)
			ans += a[i] + ADD[lx];
		return ans / 1.0 / len;
	}
	else
	{
		for(rgi i = l; i <= R[lx]; i++)
			ans += a[i] + ADD[lx];
		for(rgi i = L[rx]; i <= r; i++)
			ans += a[i] + ADD[rx];
		for(rgi i = lx + 1; i < rx; i++)
			ans += SUM[i] + ADD[i] * s;
		return ans / 1.0 / len;
	}
}
double variance(int l, int r)
{
	int len = r - l + 1, lx = block[l], rx = block[r];
	double sum = 0, quad_sum = 0, answer = 0;
	if(lx == rx)
	{
		for(rgi i = l; i <= r; i++)
		{
			sum += a[i] + ADD[lx];
			quad_sum += square(a[i] + ADD[lx]);
		}
		return quad_sum / len - square(sum / len);
	}
	for(rgi i = l; i <= R[lx]; i++)
	{
		sum += a[i] + ADD[lx];
		quad_sum += square(a[i] + ADD[lx]);
	}
	for(rgi i = L[rx]; i <= r; i++)
	{
		sum += a[i] + ADD[rx];
		quad_sum += square(a[i] + ADD[rx]);
	}
	for(rgi i = lx + 1; i <= rx - 1; i++)
	{
		sum += SUM[i] + ADD[i] * s;
		quad_sum += quad[i] + 2 * SUM[i] * ADD[i] + s * square(ADD[i]);
	}
	answer = quad_sum / len - square(sum / len);
	return answer;
}
int main()
{
	scanf("%d %d", &n, &m);
	s = (int)sqrt(n) + 1;
	for(rgi i = 1; i <= n; i++)
		scanf("%lf", &a[i]);
	for(rgi i = 1; i <= s; i++)
	{
		L[i] = R[i - 1] + 1;
		R[i] = min(R[i - 1] + s, n);
		for(rgi j = L[i]; j <= R[i]; ++j)
		{
			block[j] = i;
			SUM[i] += a[j];
			quad[i] += square(a[j]);
		}
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int op, l = 0, r = 0;
		double val = 0;
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d %d", &l, &r);
			scanf("%lf", &val);
			add(l, r, val);
		}
		if(op == 2)
		{
			scanf("%d %d", &l, &r);
			printf("%.4lf\n", average(l, r));
		}
		if(op == 3)
		{
			scanf("%d %d", &l, &r);
			printf("%.4lf\n", variance(l, r));
		}
	}
}
