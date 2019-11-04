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
const int N = 700 + 10;

int n, max_ans = -oo, min_ans = oo;
int a[N], s[N], fmax[N][N], fmin[N][N];

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
	for(rgi i = 1; i <= 2 * n; ++i)
		s[i] = s[i - 1] + a[i];
	memset(fmin, oo, sizeof(fmin));
	for(rgi i = 1; i <= 2 * n; ++i)
		fmin[i][i] = 0;
	memset(fmax, -1, sizeof(fmax));
	for(rgi i = 1; i <= 2 * n; ++i)
		fmax[i][i] = 0;
	for(rgi len = 1; len <= n; ++len)
		for(rgi l = 1; l <= 2 * n; ++l)
		{
			int r = l + len;
			if(r > 2 * n)
				break;
			for(rgi k = l; k <= r - 1; ++k)
			{
				fmax[l][r] = max(fmax[l][r], fmax[l][k] + fmax[k + 1][r] + s[r] - s[l - 1]);
				fmin[l][r] = min(fmin[l][r], fmin[l][k] + fmin[k + 1][r] + s[r] - s[l - 1]); 
			}
		}
	for(rgi i = 1; i <= n; ++i)
	{
		max_ans = max(max_ans, fmax[i][i + n - 1]);
		min_ans = min(min_ans, fmin[i][i + n - 1]);
	}
	printf("%d\n%d\n", min_ans, max_ans);
	return 0;
}

