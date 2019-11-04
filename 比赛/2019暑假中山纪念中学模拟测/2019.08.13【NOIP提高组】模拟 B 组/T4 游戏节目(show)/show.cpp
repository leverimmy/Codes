#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int N = 22;

int n, k, ans;
int lg2[1 << N];
int A[N], B[N], C[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("show.in", "r", stdin);
	freopen("show.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 1; i <= 1 << n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i)
		A[i] = read();
	for(rgi i = 1; i <= n; ++i)
		B[i] = read();
	for(rgi i = 1; i <= n; ++i)
		C[i] = read();
	for(rgl i = (1 << k) - 1; i < 1 << n; ++i)
	{
		int x = i, cnt = 0;
		ll a = 0, b = 0, c = 0;
		for(; x; x -= x & -x)
		{
			a += A[lg2[x & -x]];
			b += B[lg2[x & -x]];
			c += C[lg2[x & -x]];
			cnt++;
		}
		if(cnt >= k && a > b && a > c)
			ans++;
	}
	printf("%d", ans);
	return 0;
}

