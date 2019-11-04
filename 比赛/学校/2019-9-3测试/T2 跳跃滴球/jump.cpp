#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 1e5 + 10; 

int n, m, ans;
int vis[N];

struct BALL
{
	int a, b;
}ball[M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur)
{
	if(cur == m + 1)
	{
		ans++;
		ans %= mod;
		return;
	}
	if(vis[ball[cur].a] && vis[ball[cur].b])
		return;
	if(!vis[ball[cur].a])
	{
		vis[ball[cur].a] = 1;
		dfs(cur + 1);
		vis[ball[cur].a] = 0; 
	}
	if(!vis[ball[cur].b])
	{
		vis[ball[cur].b] = 1;
		dfs(cur + 1);
		vis[ball[cur].b] = 0;
	}
}

int main()
{
	m = read(), n = read();
	for(rgi i = 1; i <= m; ++i)
	{
		ball[i].a = read();
		ball[i].b = read();
		if(ball[i].a == ball[i].b)
			ball[i].b = n + 1;
	}
	vis[n + 1] = 1;
	dfs(1);
	printf("%d", ans);
	return 0;
}

