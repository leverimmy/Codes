#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 10 + 10;

int n, x;
int e[N][N];

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
	{
		int a = read(), b = read();
		e[a + 1][b + 1] = e[b + 1][a + 1] = 1;
	}
	for(rgi i = 1; i <= 10; ++i)
		e[i][i] = 1;
	for(rgi k = 1; k <= 10; k++)
		for(rgi i = 1; i <= 10; ++i)
			for(rgi j = 1; j <= 10; ++j)
			{
				if(i == j || j == k || k == i)
					continue;
				else
					e[i][j] |= e[i][k] & e[k][j];
			}
	x = read();
	if(e[x + 1][2])
		puts("N");
	else if (e[x + 1][3])
		puts("Y");
	else
		puts("N");
	return 0;
}

