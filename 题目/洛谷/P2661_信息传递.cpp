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
#define maxn 200010

using namespace std;

int n, ans = 0x3f3f3f3f;
int t[maxn], vis[maxn], in_circle[maxn], dis[maxn];

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

void dfs(int cur, int step)
{
	if(vis[cur])
		return;
	if(in_circle[cur])
	{
		ans = ans < step - dis[cur] ? ans : step - dis[cur];
	}
	else
	{
		in_circle[cur] = 1;
		dis[cur] = step;
		dfs(t[cur], step + 1);
		vis[cur] = 1;
	}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		t[i] = read();
	for(rgi i = 1; i <= n; ++i)
		dfs(i, 0);
	write(ans);
	return 0;
}

