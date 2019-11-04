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

void dfs(int cur, int color)
//cur -> 现在的时间长度, color ->  
{
	if(cur >= 1)
		res += dfs(cur - 1, color);
	if(cur >= k)
		res += dfs(cur - k, color);
}

int main()
{
//	freopen("pool.in", "r", stdin);
//	freopen("pool.out", "w", stdout);
	T = read(), k = read();
	for(rgi i = 1; i <= T; ++i)
	{
		int L = read(), R = read();
		int maxval = max(L, R);
		maxn = max(maxn, maxval);
	}
	dfs(maxn, 0);
	
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
