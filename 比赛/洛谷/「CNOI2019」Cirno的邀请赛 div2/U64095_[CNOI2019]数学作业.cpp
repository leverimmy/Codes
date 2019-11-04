#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define MOD 998244353
#define maxn 100050

using namespace std;

int T, ans, temp, n;
int a[maxn], vis[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

void dfs(int cur)
{
	if(cur == n)
	{
		ans += temp;
		return;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		if(vis[i])
			continue;
		vis[i] = 1;
		temp = temp ^ a[i];
		dfs(i);
		vis[i] = 0;
		temp = temp ^ a[i];
	}
}

int main()
{
	T = read();
	for(; T; T--)
	{
		memset(vis, 0, sizeof(vis));
		ans = temp = 0;
		n = read();
		for(rgi i = 1; i <= n; ++i)
			a[i] = read();
		dfs(1);
		write(ans % MOD), putchar('\n');
	}
	return 0;
}

