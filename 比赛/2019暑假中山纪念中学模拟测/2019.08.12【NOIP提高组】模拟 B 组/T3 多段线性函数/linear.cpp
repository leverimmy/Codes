#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const ll N = 100000 + 10;

ll n;
ll a[N << 1];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("linear.in", "r", stdin);
	freopen("linear.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n << 1; ++i)
		a[i] = read();
	sort(a + 1, a + (n << 1) + 1);
	printf("%lld %lld", a[n], a[n + 1]);
	return 0;
}

