#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll
#define maxn 50010
#define maxk 1000010

using namespace std;

ll T;
ll a[maxn], s[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("testdata.in","r",stdin);
	freopen("brute.out","w",stdout);
	T = read();
	for(; T; T--)
	{
		ll k = read(), n = read(), cnt = 0;
		for(rgi i = 1; i <= n; ++i)
			s[i] = 0;
		for(rgi i = 1; i <= n; ++i)
		{
			a[i] = read();
			s[i] = s[i - 1] + a[i];
		}
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = i; j <= n; ++j)
				if((s[j] - s[i - 1]) % k == 0)
					cnt++;
		printf("%lld\n", cnt);
	}
	return 0;
}

