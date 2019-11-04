#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 5010

using namespace std;

int n, m;
int a[maxn], b[maxn], jiao[maxn], bu[maxn];
int cnt, tot;

set <int> bing;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	m = read();
	for(rgi i = 1; i <= m; ++i)
		b[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int flag = 0;
		int cur = a[i];
		for(rgi j = 1; j <= m; ++j)
		{
			if(b[j] == cur)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			jiao[++cnt] = cur;
	}
	sort(jiao + 1, jiao + cnt + 1);
	for(rgi i = 1; i <= cnt; ++i)
		printf("%d ", jiao[i]);
	puts("");
	for(rgi i = 1; i <= n + m; ++i)
	{
		if(i <= n)
			bing.insert(a[i]);
		else
			bing.insert(b[i - n]);
	}
	for(set<int>::iterator it = bing.begin(); it != bing.end(); it++)
		printf("%d ", *it);
	puts("");
	for(rgi i = 1; i <= n; ++i)
	{
		int flag = 1;
		int cur = a[i];
		for(rgi j = 1; j <= m; ++j)
		{
			if(b[j] == cur)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			bu[++tot] = cur;
	}
	sort(bu + 1, bu + tot + 1);
	for(rgi i = 1; i <= tot; ++i)
		printf("%d ", bu[i]);
	return 0;
}

