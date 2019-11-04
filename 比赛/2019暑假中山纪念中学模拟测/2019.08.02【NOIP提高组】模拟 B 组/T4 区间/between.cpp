#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int
#define maxn 100010

using namespace std;

int n, len = 1, cnt, again;
int last_left, last_right;
int f[maxn];

struct GIVE
{
	int l, r;
} bet[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct GIVE a, struct GIVE b)
{
	if(a.l == b.l)
		return a.r > b.r;
	return a.l < b.l;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read();
	while(1)
	{
		if(cnt + again >= n)
			break;
		int l = read(), r = read();
		if(l == last_left && r == last_right)
		{
			again++;
			continue;
		}
		cnt++;
		last_left = bet[cnt].l = l;
		last_right = bet[cnt].r = r;
	}
	n = cnt;
	sort(bet + 1, bet + n + 1, cmp);
	f[1] = bet[1].r;
	for(rgi i = 2; i <= n; ++i)
	{
		if(f[len] >= bet[i].r)
			f[++len] = bet[i].r;
		else
		{
			int pos = upper_bound(f + 1, f + len + 1, bet[i].r, greater <int> ()) - f;
			f[pos] = bet[i].r;
		}
	}
	printf("%d", len);
	return 0;
}

