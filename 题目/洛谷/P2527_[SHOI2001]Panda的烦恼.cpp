#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010
#define maxm 100010

using namespace std;

int n, k, tot;
int a[maxn], b[maxn], ans[maxm];

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
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	ans[0] = 1;
	while(tot < k)
	{
		int _min = 2100000000, minn;
		for(rgi i = 1; i <= n; ++i)
			if(ans[b[i]]*a[i] < _min)
			{
				_min = ans[b[i]] * a[i];
				minn = i;
			}
		b[minn]++;
		if(_min != ans[tot])
			ans[++tot] = _min;
	}
	write(ans[k]);
	return 0;
}

