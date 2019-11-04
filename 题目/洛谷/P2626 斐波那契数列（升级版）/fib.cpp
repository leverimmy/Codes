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

const ll MOD = 2147483648;

int n, t, x, first = 1, sum = 1;
int fib[50] = {0, 1, 1}, cnt[1000010];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	t = sqrt(n);
	for(rgi i = 2; i <= 49; ++i)
		fib[i] = (ll)(fib[i - 1] + fib[i - 2]) % MOD;
	x = fib[n];
	printf("%d=", fib[n]);
	for(rgi i = 2; i <= fib[n]; ++i)
	{
		int flag = 0;
		while(x % i == 0)
		{
			if(first)
			{
				first = 0;
				printf("%d", i);
			}
			else
				printf("*%d", i);
			x /= i;
			sum *= i;
			if(sum == fib[n])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	return 0;
}

