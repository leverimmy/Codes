#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

int ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check(ll x)
{
	int res = 0;
	while(x)
	{
		if(x & 1)
			res++;
		x >>= 1;
	}
	return res >= 7;
}

int main()
{
	freopen("table.txt", "w", stdout);
	for(register ll i = 0; i < (1ll << 34); ++i)
	{
		if(check(i))
		{
			printf("%lld,", i);
			ans++;
		}
	}
	printf("\n%d", ans);
	return 0;
}

