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
#define maxn 510

using namespace std;

int n, ans;
int a[maxn], b[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int findp(int pos)
{
	int res1 = 0;
	for(rgi i = pos; i >= 1; i--)
	{
		if(a[i] <= a[pos])
			res1++;
		else
			break;
	}
	return res1;
}

int findq(int pos)
{
	int res2 = 0;
	for(rgi i = pos; i <= n; ++i)
	{
		if(a[i] < a[pos])
			res2++;
		else
			break;
	}
	return res2;
}

int main()
{
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		b[i] = read();
	}
	for(rgi i = 1; i <= n; ++i)
	{
		int cntp = findp(i);
		int cntq = findq(i);
		if(abs(cntp - cntq) <= 2)
			ans++;
	}
	printf("%d", ans);
	return 0;
}

