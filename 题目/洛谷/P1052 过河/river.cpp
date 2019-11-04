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

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int x, int cur_ans)
{
	if(f[x][cur_ans])	return f[x][cur_ans];
	if(x == 1)	return 0;
	for(rgi i = S; i <= T; ++i)
	{
		if(x + i <= L)
		{
			if(s.find(x + i) != s.end())
				dfs(x + i, cur_ans + 1);
			else
				dfs(x + i, cur_ans);
		}
	}
}

int main()
{
	L = read();
	S = read(), T = read(), M = read();
	for(rgi i = 1; i <= M; ++i)
	 	a[i] = read();
	return 0;
}

