#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long
#define ull unsigned long long

using namespace std;

ll T, n; 

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll Query1(ll a)
{
	return (ull)a * (a + 1) * (2 * a + 1) / 6LL;
}

ll Query2(ll a)
{
	return a * (a + 1) / 2LL; 
}

ll Get_line(ll x)
{
	ll l = 1, r = 8e5;
	while(l < r)
	{
		ll mid = l + r >> 1LL;
		if(Query1(mid) < x)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

ll Get_pos(ll x, ll line)
{
	ll before = line * (line + 1) / 2, real_pos;
	if(x <= before)
	{
		ll l = 1, r = 2 * line - 1;
		while(l < r)
		{
			ll mid = l + r >> 1;
			if(Query2(mid) < x)
				l = mid + 1;
			else
				r = mid;
		}
		real_pos = l;
	}
	else
	{
		x -= before;
		for(rgl i = 1; i <= line - 1; ++i)
		{
			x -= line - i;
			if(x <= 0)
			{
				real_pos = i;
				break;
			}
		}
		real_pos += line;
	}
	return real_pos; 
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = read();
		ll cur_line = Get_line(n);
		ll last_line = cur_line - 1;
		ll pre_sum = Query1(last_line);
		ll pre_cnt = last_line * last_line;
		ll left = n - pre_sum;
		ll cur_pos = Get_pos(left, cur_line);
		printf("%lld\n", cur_pos + pre_cnt); 
	} 
	return 0;
}
/*
5
6
9
11
21
35 
*/
