#include <cstdio>
#include <cstring>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int
#define maxn 100010

using namespace std;

int n, ans;
int a[maxn], b[maxn], c[maxn];
int rev[maxn], vis[maxn], no[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for(rgi i = 1; i <= n; ++i)
	{
		if(no[i])
			continue;
		vis[a[i]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		if(!vis[b[i]])
			no[i] = 1;
		if(!vis[c[i]])
			no[i] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
		if(no[i])
			cnt++;
	ans = cnt;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		rev[a[i]] = i;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		b[i] = read();
		vis[b[i]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
		if(!vis[i])
			no[rev[i]] = 1;
	memset(vis, 0, sizeof(vis));
	for(rgi i = 1; i <= n; ++i)
	{
		c[i] = read();
		vis[c[i]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
		if(!vis[i])
			no[rev[i]] = 1;
	for(rgi i = 1; i <= 1000; ++i)
		solve();
	printf("%d", ans);
	return 0;
}

