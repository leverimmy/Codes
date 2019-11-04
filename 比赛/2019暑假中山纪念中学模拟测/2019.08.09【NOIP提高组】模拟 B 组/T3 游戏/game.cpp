#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000 + 10;

int n, cnt;
int prime[N];
bool ok[N][N];
ll f[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check(int x)
{
	if(x <= 1)
		return 0;
	for(rgi i = 2; i <= x / i; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

void init()
{
	for(rgi i = 1; i <= N; ++i)
		if(check(i))
			prime[cnt++] = i;
}

ll dfs(int cur, int step)
{
	cur = max(cur, 0);
	if(ok[cur][step])
		return f[cur][step];
	if(cur == 0 || step == cnt || prime[step] > cur)
		return 1;
	ok[cur][step] = 1;
	f[cur][step] = dfs(cur, step + 1);
	ll res = 1;
	for(rgi i = 1; res * prime[step] <= cur; ++i)
	{
		res *= prime[step];
		f[cur][step] += dfs(cur - res, step + 1);
	}
	return f[cur][step];
}

int main()
{
	n = read();
	init();
	printf("%lld", dfs(n, 0));
	return 0;
}

