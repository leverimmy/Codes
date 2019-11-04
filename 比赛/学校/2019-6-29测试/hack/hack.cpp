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
#define inf 0x3f3f3f3f

using namespace std;

int n, ans = inf, min_siz3 = inf;
int c[maxn], s[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur, int siz1, int siz2, int siz3)
{
	if(cur == n + 1)
	{
		if(siz1 != siz2)
			return;
		else
		{
			if(siz3 < min_siz3)
			{
				ans = min(ans, siz1 + siz3);
				min_siz3 = siz3;
			}//update the answer
			return;
		}
	}
	if(abs(siz1 - siz2) > (s[n] - siz1 - siz2 - siz3))//cut cut cut
		return;
	if(siz3 > min_siz3)//cut cut cut
		return;
	dfs(cur + 1, siz1 + c[cur], siz2, siz3);
	dfs(cur + 1, siz1, siz2 + c[cur], siz3);
	dfs(cur + 1, siz1, siz2, siz3 + c[cur]);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		c[i] = read();
		s[i] = s[i - 1] + c[i];
	}
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}

