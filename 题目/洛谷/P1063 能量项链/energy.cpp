#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, ans = -oo;
int a[N], f[N][N];

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
	for(rgi len = 2; len <= n + 1; ++len)
		for(rgi l = 1; l <= 2 * n; ++l)
		{
			int r = l + len - 1;
			if(r > 2 * n)
				break;
			for(rgi k = l + 1; k <= r - 1; ++k)
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
		}
	for(rgi i = 1; i <= n; ++i)
		ans = max(ans, f[i][i + n]);
	printf("%d", ans);
	return 0;
}

