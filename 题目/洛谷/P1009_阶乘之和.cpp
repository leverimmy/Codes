#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, flag;
int a[110] = {1, 1}, ans[110] = {1, 1};

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

int main()
{
	n = read();
	for(rgi i = 2; i <= n; ++i)
	{
		int x, y;
		x = y = 0;
		for(rgi j = 1; j <= a[0]; ++j)
		{
			a[j] *= i;
			a[j] += x;
			x = a[j] / 10;
			a[j] %= 10;
		}
		if(x > 0)
			a[++a[0]] = x;
		a[0]++;
		for(rgi j = 1; j <= ans[0] || j <= a[0]; ++j)
		{
			ans[j] += a[j];
			ans[j] += y;
			y = ans[j] / 10;
			ans[j] %= 10;
		}
		if(y > 0)
			ans[++ans[0]] = y;
		ans[0]++;
	}
	for(rgi i = 100; i >= 1; i--)
	{
		if(ans[i])
			flag = 1;
		if(flag)
			write(ans[i]);
	}
	return 0;
}

