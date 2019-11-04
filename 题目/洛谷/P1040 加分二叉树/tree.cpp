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
const int N = 30 + 10;

int n;
int w[N], f[N][N], rt[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Out(int l, int r)
{
	if(l > r)	return;
	int cur_root = rt[l][r];
	printf("%d ", cur_root);
	Out(l, cur_root - 1), Out(cur_root + 1, r);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		w[i] = read();
	for(rgi len = 1; len <= n; ++len)
		for(rgi l = 1; l + len - 1 <= n; ++l)
		{
			int r = l + len - 1;
			f[l][r] = -oo;
			for(rgi k = l; k <= r; ++k)
			{
				int left = k == l ? 1 : f[l][k - 1];
				int right = k == r ? 1 : f[k + 1][r];
				int score = w[k] + left * right;
				if(l == r)	score = w[k];
				if(f[l][r] < score)
				{
					f[l][r] = score;
					rt[l][r] = k;
				}
			}
		}
	printf("%d\n", f[1][n]);
	Out(1, n);
	return 0;
}

