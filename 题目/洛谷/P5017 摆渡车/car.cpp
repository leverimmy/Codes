#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int N = 500 + 10;

int n, m, t[N];
ll f[N][N], ans = oo, tmax = - oo, tmin = oo;

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
	memset(f, oo, sizeof(f));
	for(rgi i = 1; i <= n; ++i)
	{
		t[i] = read();
		tmax = max(tmax, t[i]);
		tmin = min(tmin, t[i]);
	}
	for(rgi i = 1; i <= n; ++i)
		t[i] -= tmin;
	sort(t + 1, t + n + 1);
	/*
	f[i][j] -> the ith person have waited j minutes, the sum of the first i - 1 people have waited
	f[i][j + t[i - 1] - t[i]] = f[i - 1][j] + t[i - 1] + j - t[i](if the next person can catch this bus)
	(t[i - 1] + j >= t[i])
	f[i][j + t[i - 1] + m + k - t[i]] = f[i - 1][j] + t[i - 1] + m + k - t[i](if the next person can catch this bus until it returns)
	(t[i - 1] + j + m >= t[i])
	f[i][k] = f[i - 1][j] + k(if the next person cannot catch this bus even if it returns)
	(t[i - 1] + j + m < t[i])
	*/
	for(rgi i = 0; i < m << 1; ++i)
		f[1][i] = i;
	for(rgi i = 2; i <= n; ++i)
		for(rgi j = 0; j < m << 1; ++j)
			if(f[i - 1][j] < oo)
			{
				if(t[i - 1] + j >= t[i])
					f[i][j + t[i - 1] - t[i]] = min(f[i][j + t[i - 1] - t[i]], f[i - 1][j] + t[i - 1] + j - t[i]);
				int r;
				if(t[i - 1] + j + m >= t[i])
					r = 0;
				else
					r = t[i] - t[i - 1] - j - m;
				for(rgi k = r; t[i - 1] + j + m + k - t[i] < m << 1; ++k)
					if(t[i - 1] + j + m + k >= t[i])
						f[i][j + t[i - 1] + m + k - t[i]] = min(f[i][j + t[i - 1] + m + k - t[i]], f[i - 1][j] + t[i - 1] + j + m + k - t[i]);
				if(t[i - 1] + j + m < t[i])
					for(rgi k = 0; k < m << 1; ++k)
						f[i][j] = min(f[i][j], f[i - 1][j] + k);
			}
	for(rgi i = 0; i < m << 1; ++i)
		ans = min(ans, f[n][i]);
	printf("%lld", ans);
	return 0;
}
/*
5 5
11 13 1 5 5
*/

