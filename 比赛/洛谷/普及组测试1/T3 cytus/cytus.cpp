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

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
	{
		c[i] = read();
		a[i][0] = read();
		flag += a[i][0];
		for(rgi j = 1; j <= a[i][0]; ++j)
			a[i][j] = read();
	}
	q = read();
	for(rgi i = 1; i <= q; ++i)
		x[i] = read();
	if(!flag)
		printf("%d %d", n - q, n - q);
	return 0;
}

