#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, m;
int a[N];
ll s[N];

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
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		s[i] = s[i - 1] + a[i];
	}
	for(rgi i = n + 1; i <= n << 1; ++i)
	{
		a[i] = a[i - n];
		s[i] = s[i - 1] + a[i];
	}
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int pos = read(), val = read();
		ll maxn = -oo;
		a[pos] = a[pos + n] = val;
		for(rgi i = 1; i <= n << 1; ++i)
			s[i] = s[i - 1] + a[i];
		for(rgi l = 1; l <= n; ++l)
			for(rgi len = 1; len < n; ++len)
			{
				int r = l + len - 1;
				maxn = max(maxn, s[r] - s[l - 1]);
			}
		printf("%d\n", maxn);
	}
	return 0;
}

