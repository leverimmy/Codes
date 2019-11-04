#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 1000 + 10;

int n;
int f[N], e[N], w[N];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		f[i] = read();
		e[i] = read();
		w[i] = read();
	}
	printf("%d", n);
	return 0;
}

