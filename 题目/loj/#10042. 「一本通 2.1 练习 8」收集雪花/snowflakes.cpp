#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000000 + 10;

int n, ans;
int vis[N];

queue <int> q;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("snow0.in", "r", stdin);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int x=read();
		if()
		ans = max(ans, r - l + 1);
	}
	printf("%d", ans);
	return 0;
}

