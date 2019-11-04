#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const ll mod = 1e9 + 7;
const int N = 2e5 + 10;

ll T, k, L, R;
ll f[N][2], s[N];

il ll read()
{
	register long long x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll dfs(ll cur, ll last)
//cur = 0 -> 1, last = 1 -> k
{
	if(f[cur][last])	return f[cur][last];
	if(cur == 0)	return 1;
	ll res = 0;
	if(cur >= 1)	res += dfs(cur - 1, 0);
	if(cur >= k && last == 0)	res += dfs(cur - k, 1);
	return f[cur][last] = res % mod;
}

int main()
{
//	freopen("pool.in", "r", stdin);
//	freopen("pool.out", "w", stdout);
	T = read(), k = read();
	for(register long long i = 1; i <= 100000; ++i)
	{
		f[i][0] = dfs(i, 0);
		f[i][1] = dfs(i, 1);
		s[i] = (s[i - 1] + max(f[i][0], f[i][1])) % mod;
	}
	for(register long long i = 1; i <= T; ++i)
	{
		L = read(), R = read();
		printf("%lld\n", (s[R] - s[L - 1] + mod) % mod);
	}
	return 0;
}
/*
3 3
3 3
1 4
1 5

*/
