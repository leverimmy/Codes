#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

int a, b;
ll p[13] = {1};
int f[12][10];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= 12; ++i)
		p[i] = p[i - 1] * 10;
}

int Query(int x)
{
	int res = 0, digits = 0, y, last;
	while(p[digits] <= x)
		digits++;
	for(rgi i = 1; i < digits; ++i)
		for(rgi j = 1; j <= 9; ++j)
			res += f[i][j];
	y = x / p[digits - 1];
	for(rgi i = 1; i < y; ++i)
		res += f[digits][i];
	x %= p[digits - 1];
	last = y;
	for(rgi i = digits - 1; i >= 1; --i)
	{
		y = x / p[i - 1];
		for(rgi j = 0; j < y; ++j)
			if(abs(last - j) >= 2)
				res += f[i][j];
		if(abs(last - y) < 2)
			break;
		last = y;
		x %= p[i - 1];
	}
	return res;
}

int main()
{
	a = read(), b = read();
	init();
	for(rgi i = 0; i <= 9; ++i)
		f[1][i] = 1;
	for(rgi i = 2; i <= 11; ++i)
		for(rgi j = 0; j <= 9; ++j)
			for(rgi k = 0; k <= 9; ++k)
				if(abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
	printf("%d", Query(b + 1) - Query(a));
	return 0;
}

