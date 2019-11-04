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
#define maxn 5010

using namespace std;

int n, cnt;
int prime[maxn], vis[maxn];
ll f[maxn] = {1};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		vis[i] = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		if(i < 2)
			vis[i] = 0;
		for(rgi j = 2; j <= i / j; j++)
		{
			if(i % j == 0)
			{
				vis[i] = 0;
				break;
			}
		}
		if(vis[i])
			prime[++cnt] = i;
	}
}

int main()
{
	n = read();
	init();
	for(rgi i = 1; i <= cnt; ++i)
		for(rgi j = prime[i]; j <= n; ++j)
			f[j] += f[j - prime[i]];
	printf("%lld", f[n]);
	return 0;
}

