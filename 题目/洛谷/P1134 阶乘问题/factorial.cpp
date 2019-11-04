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

int n, t, f;
int ans = 1, mul = 1; 

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int ksm(int base, int power)
{
	int res = 1 % 10;
	while(power)
	{
		if(power & 1)
			res = res * base % 10;
		base = base * base % 10;
		power >>= 1;
	}
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int cur = i;
		while(cur % 2 == 0)	t++, cur /= 2;
		while(cur % 5 == 0) f++, cur /= 5;
		ans *= cur;
		ans %= 10;
	}
	mul = t > f ? ksm(2, t - f) : ksm(5, f - t);
	printf("%d", ans * mul % 10);
	return 0;
}

