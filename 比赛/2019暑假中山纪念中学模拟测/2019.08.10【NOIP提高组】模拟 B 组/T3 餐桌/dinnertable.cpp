#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2000 + 10;
const int M = 2000 + 10;

int n, m, ans = -oo, tmp, minn = oo;
int a[N][M];
char e[N][M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Debug1()
{
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			printf("%c", e[i][j]);
		puts("");
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
		{
			char ch = ' ';
			while(ch == ' ' || ch == '\n')
				ch = getchar();
			a[i][j] = ch == 'X' ? -1 : 1;
		}
	}
//	Debug1();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(a[i][j] == -1)
				continue;
			if(a[i - 1][j] == -1)
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j] + 1;
		}
	//a[i][j] -> 第i行第j列这个位置，这一列往上连续.的个数
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			if(a[i][j] > 0)
			{
				tmp = j;//横着拓展 
				int minn = oo; 
				while(a[i][tmp] > 0)
				{
					if(a[i][tmp] < minn)
						minn = a[i][tmp];
					ans = min(ans, (tmp - j + 1 + minn) * 2 - 1);
					tmp++;
				}
			}
	printf("%d", ans);
	return 0;
}

