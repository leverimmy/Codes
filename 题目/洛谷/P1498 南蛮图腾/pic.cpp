#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 15

using namespace std;

const char left = '/', mid = '_', right = '\\';

int n, h = 2;
char map[1050][2050];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= 1030; ++i)
		for(rgi j = 1; j <= 2050; ++j)
			map[i][j] = ' ';
	map[1][1] = left;
	map[1][2] = mid;
	map[1][3] = mid;
	map[1][4] = right;
	map[2][2] = left;
	map[2][3] = right;
	/*
		 /\    	->	 /__\
		/__\	-> 	  /\
	*/
}

int main()
{
	n = read();
	init();
	for(rgi i = 1; i < n; ++i)
	{
		for(rgi j = 1; j <= h; ++j)
		{
			for(rgi k = 1; k <= h << 1; ++k)
				map[j + h][k + h] = map[j][k + (h << 1)] = map[j][k];
		}
		h *= 2;
	}
	for(rgi i = h; i >= 1; i--)
	{
		for(rgi j = 1; j <= h << 1; ++j)
			printf("%c", map[i][j]);
		puts("");
	}
	return 0;
}
