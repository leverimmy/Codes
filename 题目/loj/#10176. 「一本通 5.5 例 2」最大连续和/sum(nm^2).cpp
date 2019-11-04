#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 200000 + 10;
const int oo = 0x3f3f3f3f;

int n, m, ans = -oo;
int a[N], f[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		f[i] = -oo;
	}
	//f[i]表示长度不超过m的以a[i]结尾的最大子段连续和
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi k = 1; k <= m; ++k)
		{
			int sum = 0;
			for(rgi j = i - k + 1; j <= i; ++j)
				sum += a[j];
			f[i] = max(f[i], sum);
		}
	}
	for(rgi i = 1; i <= n; ++i)
		ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}

