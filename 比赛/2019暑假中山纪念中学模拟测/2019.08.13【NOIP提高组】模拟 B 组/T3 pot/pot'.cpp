#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int N = 100000 + 10;

int n, m;
int a[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = a[i + n] = read();
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int pos = read(), val = read(), cur_ans = 0;
		a[pos] = a[pos + n] = val;
		for(rgi l = 1; l <= n; ++l)
			for(rgi len = 1; len < n; ++len)
			{
				int r = l + len - 1, res = 0;
				for(rgi k = l; k <= r; ++k)
					res += a[k];
				cur_ans = max(cur_ans, res);
			}
		printf("%d\n", cur_ans);
	}
	return 0;
}

