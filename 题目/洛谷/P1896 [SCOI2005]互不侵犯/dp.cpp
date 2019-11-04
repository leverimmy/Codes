#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#define ll long long
#define rgi register int
#define rgl register long long
#define int long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 10;
const int K = 100;

int n, k, ans;
int f[1 << N][N][K];//state, line, tot

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool Check(int x)
{
	return !(x << 1 & x) && !(x >> 1 & x);
}

signed main()
{
	n = read(), k = read();
	for(rgi i = 0; i <= (1 << n) - 1; ++i) if(Check(i))
		f[i][1][__builtin_popcountl(i)] = 1;
	for(rgi i = 2; i <= n; ++i)
		for(rgi j = 0; j <= (1 << n) - 1; ++j) if(Check(j))//this line
			for(rgi m = 0; m <= (1 << n) - 1; ++m) if(Check(m))//last line
				for(rgi l = __builtin_popcountl(j); l <= k; ++l)
					if(!(j & m) && !(j << 1 & m) && !(j >> 1 & m))
						f[j][i][l] += f[m][i - 1][l - __builtin_popcountl(j)];
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 0; j <= (1 << n) - 1; ++j)
			for(rgi l = 0; l <= k; ++l)
			{
				printf("f[%d%d%d][%d][%d] = %d\n", (j >> 2) & 1, (j >> 1) & 1, j & 1, i, l, f[j][i][l]);
//				cout << setw(6) << "i : " << i << " " << "j : " << j << " " << "L : " << l << "f : " << f[j][i][l];
//				if(i == n && l == k)	putchar('?');
			}
		cout << endl;
	}*/
	for(rgi i = 0; i <= (1 << n) - 1; ++i) ans += f[i][n][k];
	printf("%lld", ans);
	return 0;
}

