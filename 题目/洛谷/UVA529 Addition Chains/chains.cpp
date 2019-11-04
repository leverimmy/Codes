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
#define maxn 10010

using namespace std;

int n, ok, dep;
int ans[maxn];

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
	if(ok)
		return;
	if(cur == step)
	{
		if(ans[cur] == n)
			ok = 1;
		return;
	}
	for(rgi i = 0; i <= cur; ++i)
		for(rgi j = i; j <= cur; ++j)
			if(ans[i] + ans[j] > ans[cur] && ans[i] + ans[j] <= n)
			{
				int sum = ans[i] + ans[j];
				for(rgi k = cur + 2; k <= step; ++k)
					sum <<= 1;
				if(sum < n)
					continue;
				ans[cur + 1] = ans[i] + ans[j];
				dfs(cur + 1, step);
				if(ok)
					return;
			}
}

int main()
{
	while(n = read())
	{
		if(!n)
			break;
		memset(ans, 0, sizeof(ans));
		ans[ok = 0] = 1;
		int tmp = n, dep = 0;
		while(tmp >>= 1)
			dep++;
		while(!ok)
			dfs(0, dep++);
		for(rgi i = 0; i < dep - 1; ++i)
			printf("%d ", ans[i]);
		printf("%d", ans[dep - 1]);
		puts("");
	}
	return 0;
}

