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

ll fib[99] = {0, 1, 1};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("ttt.txt", "w", stdout);
	for(rgi i = 3; i <= 40; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
	for(rgi i = 1; i <= 40; ++i)
		printf("%lld,", fib[i]);
	return 0;
}

