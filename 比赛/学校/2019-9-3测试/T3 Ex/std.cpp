#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 250;

int n, a[N];
char op[N];
double ans, e[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double Query(int digit)
{
	double f[N] = {0};
	if(a[0] & (1 << digit))
		f[0] = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		if(a[i] & (1 << digit))
		{
			if(op[i] == '&')
				f[i] = e[i] * f[i - 1] + (1 - e[i]) * f[i - 1];
			if(op[i] == '|')
				f[i] = e[i] * f[i - 1] + (1 - e[i]);
			if(op[i] == '^')
				f[i] = e[i] * f[i - 1] + (1 - e[i]) * (1 - f[i - 1]);
		}
		else
		{
			if(op[i] == '&')
				f[i] = e[i] * f[i - 1];
			if(op[i] == '|')
				f[i] = e[i] * f[i - 1] + (1 - e[i]) * f[i - 1];
			if(op[i] == '^')
				f[i] = e[i] * f[i - 1] + (1 - e[i]) * f[i - 1];
		}
	}
	return f[n];
}

int main()
{
	n = read(); 
	for(rgi i = 0; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char tmp[5];
		scanf("%s", tmp);
		op[i] = tmp[0];
	}
	for(rgi i = 1; i <= n; ++i)
		scanf("%lf", &e[i]);
	for(rgi i = 0; i <= 20; ++i)
		ans += (double)(1 << i) * Query(i);
	printf("%.4f", ans); 
	return 0;
}

