#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e6 + 10;

int n, a[N];
int f[N][4][2];
//f[i][j][1] -> ith person, used j queues, choose cur
//f[i][j][0] -> ith person, used j queues, not choose cur

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("jx.in", "r", stdin);
//	freopen("jx.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 0; i <= n; ++i)
		for(rgi j = 0; j <= 3; ++j)
			f[i][j][0] = f[i][j][1] = -oo;
	f[0][0][0] = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 0; j <= 3; ++j)
		{
			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);//不选 
			f[i][j][1] = f[i - 1][j][1] + a[i]; //选，但不开 
			if(j > 0)//开 
				f[i][j][1] = max(f[i][j][1], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + a[i]);
		}
	}
	printf("%d", max(f[n][3][0], f[n][3][1]));
	return 0;
}
/*
3
-1
-1
-1

*/
