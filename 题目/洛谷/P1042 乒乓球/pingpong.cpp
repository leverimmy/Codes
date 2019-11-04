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
#define maxn 100010

using namespace std;

int len, hh_11, hh_21, ll_11, ll_21;
char ch, s[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void solve_11()
{
	if(hh_11 >= 11 && hh_11 - ll_11 >= 2)
	{
		printf("%d:%d\n", hh_11, ll_11);
		hh_11 = ll_11 = 0;
	}
	if(ll_11 >= 11 && ll_11 - hh_11 >= 2)
	{
		printf("%d:%d\n", hh_11, ll_11);
		hh_11 = ll_11 = 0;
	}
}

void solve_21()
{
	if(hh_21 >= 21 && hh_21 - ll_21 >= 2)
	{
		printf("%d:%d\n", hh_21, ll_21);
		hh_21 = ll_21 = 0;
	}
	if(ll_21 >= 21 && ll_21 - hh_21 >= 2)
	{
		printf("%d:%d\n", hh_21, ll_21);
		hh_21 = ll_21 = 0;
	}
}

int main()
{
	while(ch = getchar())
	{
		if(!isalpha(ch))
			continue;
		if(ch == 'E')
			break;
		s[++len] = ch;
	}
	for(rgi i = 1; i <= len; ++i)
	{
		if(s[i] == 'W')
			hh_11++;
		else if(s[i] == 'L')
			ll_11++;
		solve_11();
	}
	if(hh_11 || ll_11)
		printf("%d:%d\n", hh_11, ll_11);
	else
		puts("0:0");
	puts("");
	for(rgi i = 1; i <= len; ++i)
	{
		if(s[i] == 'W')
			hh_21++;
		else if(s[i] == 'L')
			ll_21++;
		solve_21();
	}
	if(hh_21 || ll_21)
		printf("%d:%d\n", hh_21, ll_21);
	else
		puts("0:0");
	return 0;
}
