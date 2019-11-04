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
#define maxn 5010

using namespace std;

int n, ans = -1;
int f[maxn];

struct stick
{
	int l, w;
} s[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct stick a, struct stick b)
{
	if(a.l == b.l)
		return a.w < b.w;
	return a.l < b.l;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		s[i].l = read();
		s[i].w = read();
	}
	sort(s + 1, s + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
	{
		f[i] = 1;
		for(rgi j = 1; j < i; ++j)
			if(s[i].l > s[j].l && s[i].w < s[j].w)
				f[i] = max(f[i], f[j] + 1);
	}
	for(rgi i = 1; i <= n; ++i)
		ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}

