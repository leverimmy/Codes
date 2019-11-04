#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int T, k, L, R, ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur, int last)
//last = 0 -> 1, last = 1 -> k
{
	if(cur > R)
		return;
	if(cur >= L)
	{
		ans++;
		ans %= mod;
	}
	dfs(cur + 1, 0);
	if(last == 0)	dfs(cur + k, 1);
}

int main()
{
	freopen("pool.in", "r", stdin);
	freopen("pool.out", "w", stdout);
	T = read(), k = read();
	for(rgi i = 1; i <= T; ++i)
	{
		L = read(), R = read(), ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
/*
3 3
3 3
1 4
1 5

*/
