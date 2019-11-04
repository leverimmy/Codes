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
const int N = 1e5 + 10;

int n; int f[N][4][2];//f[i][j][k] -> ith tree, current j color, 0 -> high, 1 -> low

struct data
{
	int a, b, c;
} in[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int cur, int color, int r)
{
	if(f[cur][color][r])	return f[cur][color][r];
	if(cur == 1)
	{
		
	}
	else if(cur == n)
	{
		
	}
	else
	{
		
	}
	return f[cur][color][r] = res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		in[i].a = read(), in[i].b = read(), in[i].c = read();
	for(rgi i = 1; i <= n; ++i)
	{
		
	}
	return 0;
}

