#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010

using namespace std;

int m, n, ans;
bool vis[maxn];

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
	m = read(), n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int x = read();
		if(!vis[x])
		{
			if(q.size() == m)
			{
				int cur = q.front();
				vis[cur] = 0;
				q.pop();
			}
			q.push(x);
			vis[x] = 1;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}

