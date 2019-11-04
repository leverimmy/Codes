#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#define ll long long
#define il inline
#define rgi register int
#define maxn 1010

using namespace std;

int n, m, cnt;
int vis[maxn];

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
		if(vis[x])
			continue;
		if(q.size() >= m)
		{
			vis[q.front()] = 0;
			q.pop();
		}
		vis[x] = 1;
		q.push(x);
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}

