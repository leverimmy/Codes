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
#define maxn 2000010

using namespace std;

int n, k, p, ans;
int color[maxn], price[maxn];
int lg2[maxn] = { -1, 0}, f[maxn][50];

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

int query(int l, int r)
{
	int len = lg2[r - l + 1];
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}

int main()
{
	n = read(), k = read(), p = read();
	for(rgi i = 1; i <= n; ++i)
	{
		color[i] = read();
		price[i] = read();
		lg2[i] = lg2[i >> 1] + 1;
		f[i][0] = price[i];
	}
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	for(rgi i = 0; i < k; ++i)
	{
		int s1, s2, last;
		s1 = s2 = last = 0;
		for(rgi j = 1; j <= n; ++j)
			if(color[j] == i)
				s1++;
		ans += s1 * (s1 - 1) >> 1;
		for(rgi j = 1; j <= n; ++j)
			if(color[j] == i)
			{
				if(!last)
				{
					last = j;
					continue;
				}
				if(query(last, j) > p)
					s2++;
				else
				{
					ans -= s2 * (s2 + 1) >> 1;
					s2 = 0;
				}
				last = j;
			}
		if(s2)
			ans -= s2 * (s2 + 1) >> 1;
	}
	printf("%d", ans);
	return 0;
}

