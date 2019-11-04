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
const int N = 50 + 10;

int n, c, ans = oo, tot;

struct in
{
	int pos, w;
} l[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur_pos, int cur_ans, int cur_watt, int cur_l, int cur_r)//[cur_l, cur_r] -> 灯关了的区间 
{
	if(cur_ans >= ans)	return;
	if(cur_watt == 0)
	{
		ans = cur_ans;
		return;
	}
	if(cur_l > 1)	dfs(cur_l - 1, cur_ans + (l[cur_pos].pos - l[cur_l - 1].pos) * cur_watt, cur_watt - l[cur_l - 1].w, cur_l - 1, cur_r);//go left
	if(cur_r < n)	dfs(cur_r + 1, cur_ans + (l[cur_r + 1].pos - l[cur_pos].pos) * cur_watt, cur_watt - l[cur_r + 1].w, cur_l, cur_r + 1);//go right
}

int main()
{
	n = read(), c = read();
	for(rgi i = 1; i <= n; ++i)
	{
		l[i].pos = read();
		l[i].w = read();
		tot += l[i].w;
	}
	dfs(c, 0, tot - l[c].w, c, c);
	printf("%d", ans);
	return 0;
}

