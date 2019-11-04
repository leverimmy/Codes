#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000 + 10;
const int mod = 20040301;

int n, ans;
char opp[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int step, int cur_xio, int my_kang, int opp_kang, bool me_dead, bool opp_dead)
{
	if(step == n + 1 && (opp_dead || opp_kang < 0) && cur_xio >= 0)
	{
		ans = (ll)(ans + 1) % mod;
		return;
	}
	if(cur_xio < 0 || my_kang < 0 || opp_kang < 0 || me_dead || opp_dead)
		return;
	if(opp[step] == 'X')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, me_dead, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang, me_dead, 1);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang, me_dead, 1);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang, me_dead, 1);//L
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//K
	}
	else if(opp[step] == 'M')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, 1, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang, me_dead, opp_dead);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang, me_dead, 1);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang, me_dead, 1);//L
		dfs(step + 1, cur_xio, my_kang - 1, opp_kang, me_dead, opp_dead);//K
	}
	else if(opp[step] == 'T')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, me_dead, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang, me_dead, opp_dead);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang, me_dead, opp_dead);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang, me_dead, 1);//L
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//K
	}
	else if(opp[step] == 'S')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, 1, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang, 1, opp_dead);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang, me_dead, opp_dead);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang, me_dead, 1);//L
		dfs(step + 1, cur_xio, my_kang - 2, opp_kang, me_dead, opp_dead);//K
	}
	else if(opp[step] == 'L')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, 1, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang, 1, opp_dead);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, 1, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang, 1, opp_dead);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang, me_dead, opp_dead);//L
		dfs(step + 1, cur_xio, my_kang - 3, opp_kang, me_dead, opp_dead);//K
	}
	else if(opp[step] == 'K')
	{
		dfs(step + 1, cur_xio + 1, my_kang, opp_kang, me_dead, opp_dead);//X
		dfs(step + 1, cur_xio - 1, my_kang, opp_kang - 1, me_dead, opp_dead);//M
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//T
		dfs(step + 1, cur_xio - 2, my_kang, opp_kang - 2, me_dead, opp_dead);//S
		dfs(step + 1, cur_xio - 3, my_kang, opp_kang - 3, me_dead, opp_dead);//L
		dfs(step + 1, cur_xio, my_kang, opp_kang, me_dead, opp_dead);//K
	}
}

int main()
{
//	freopen("duliu.in", "r", stdin);
//	freopen("duliu.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
		cin >> opp[i];
	dfs(2, 1, 3, 3, 0, 0);
	printf("%d", ans);
	return 0;
}
/*
3
X X X

X T M

X K M

X X S

X X M
*/

