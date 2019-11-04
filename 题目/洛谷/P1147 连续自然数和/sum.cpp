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
#define maxn 100010

using namespace std;

int m, t, cnt;
int k1[maxn], k2[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	m = read();
	m *= 2;
	t = sqrt(m);
//	m = (l + r)(r - l + 1) / 2
//  2 * m = k1 * k2 = (l + r)(r - l + 1) (k1 > k2)
//  l = (k1 - k2 + 1) / 2
//	r = (k1 + k2 - 1) / 2
	for(rgi i = 1; i <= t; ++i)
		if(m % i == 0)
		{
			if((m / i - i) & 1)
			{
				++cnt;
				k1[cnt] = m / i;
				k2[cnt] = i;
			}
		}
	for(rgi i = cnt; i > 1; i--)
	{
		int l = (k1[i] - k2[i] + 1) >> 1;
		int r = (k1[i] + k2[i] - 1) >> 1;
		printf("%d %d\n", l, r);
	}
	return 0;
}

