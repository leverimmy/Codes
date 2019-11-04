#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, tot;
int pos[maxn], ans[maxn];

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

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int val = read();
		pos[val] = i;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		int val = read();
		int cur = pos[val];
		if(cur > ans[tot])
			ans[++tot] = cur;
		else
		{
			int l = 0, r = tot;
			while(l <= r)
			{
				int mid = (l + r) >> 1;
				if(cur < ans[mid])
					r = mid - 1;
				else
					l = mid + 1;
			}
			ans[l] = cur;
		}
	}
	write(tot);
	return 0;
}

