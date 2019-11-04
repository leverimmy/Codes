#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

ll T, k, L, R;
ll f[N][2];

il ll read()
{
	register long long x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll dfs(int cur, int _next)
//last = 0 -> 1, _next = 1 -> k
{
	if(cur <= 0)	return 0;
	if(cur == 1)	return 1;
	if(cur == k && _next == k)	return 1;
	if(f[cur][_next])	return f[cur][_next];
	
	ll res = 0;
	if(_next == 0)	res += dfs(cur - 1, 0), res += dfs(cur - k, 1); 
	if(_next == 1)	res += dfs(cur - k, 0);
	
	return f[cur][_next] = res % mod;
}

int main()
{
//	freopen("pool.in", "r", stdin);
//	freopen("pool.out", "w", stdout);
	T = read(), k = read();
	for(register long long i = 1; i <= T; ++i)
	{
		L = read(), R = read();
		ll a = dfs(R, 0);
		ll b = dfs(R, 1);
		ll c = dfs(L - 1, 0);
		ll d = dfs(L - 1, 1);
		cout << a << " " << b << " " << c << " " << d <<endl;
		printf("%lld\n", max(a, b) - max(c, d));
	}
	return 0;
}
/*
3 3
3 3
1 4
1 5

2
7
11

*/
