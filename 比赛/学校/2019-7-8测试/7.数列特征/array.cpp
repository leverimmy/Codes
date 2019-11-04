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

const int inf = 0x3f3f3f3f;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int n, big = -inf, small = inf, sum;

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int cur = read();
		big = max(big, cur);
		small = min(small, cur);
		sum += cur;
	}
	printf("%d\n%d\n%d\n", big, small, sum);
	return 0;
}

