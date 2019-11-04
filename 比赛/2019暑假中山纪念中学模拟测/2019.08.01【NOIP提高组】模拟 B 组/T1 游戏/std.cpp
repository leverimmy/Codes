#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 1010

using namespace std;

int T;
int sum_hang[maxn], sum_lie[maxn];
int e[maxn][maxn], f[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
//0->L, 1->W
int main()
{
	T = read();
	for(; T; T--)
	{
		int n = read();
		memset(sum_hang, 0, sizeof(sum_hang));
		memset(sum_lie, 0, sizeof(sum_lie));
		memset(f, 0, sizeof(f));
		for(rgi i = 1; i <= n; ++i)//i -> hang
		{
			for(rgi j = 1; j <= n; ++j)//j -> lie
			{
				e[i][j] = read();
				sum_hang[i] += e[i][j];
				sum_lie[j] += e[i][j];
				if(f[i][j - 1] == 1 && f[i - 1][j] == 1)
					f[i][j] = 0;
				else if(f[i][j - 1] == 1 && f[i - 1][j] == 0)
				{
					if(sum_hang[i] % 2 == 0)
						f[i][j] = 1;
					else
						f[i][j] = 0;
				}
				else if(f[i][j - 1] == 0 && f[i - 1][j] == 1)
				{
					if(sum_lie[j] % 2 == 0)
						f[i][j] = 1;
					else
						f[i][j] = 0;
				}
				else if(f[i][j - 1] == 0 && f[i - 1][j] == 0)
				{
					if(sum_hang[i] % 2 == 0 || sum_lie[j] % 2 == 0)
						f[i][j] = 1;
					else
						f[i][j] = 0;
				}
			}
		}
		if(f[n][n])
			puts("W");
		else
			puts("L");
	}
	return 0;
}

