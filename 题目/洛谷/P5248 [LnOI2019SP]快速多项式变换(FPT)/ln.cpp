#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 1000010

using namespace std;

ll m, fm, cnt;
ll num[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	m = read(), fm = read();
	for(; fm;)
	{
		num[++cnt] = fm % m;
		fm /= m;
	}
	printf("%lld\n", cnt);
	for(rgi i = 1; i <= cnt; ++i)
		printf("%lld ", num[i]);
	return 0;
}

