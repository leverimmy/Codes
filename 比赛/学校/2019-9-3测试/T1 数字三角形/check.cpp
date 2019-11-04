#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <ctime>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;

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
	return a * (a + 1) * (2 * a + 1) / 6LL;
}

ll Query2(ll a)
{
	return a * (a + 1) / 2LL; 
}

ll Get_line(ll x)
{
	ll l = 1, r = 1e5;
	while(l < r)
	{
		ll mid = l + r >> 1;
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

ll Get_pos_another(ll x, ll line)
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
		ll l = line + 1, r = 2 * line - 1;
		while(l < r)
		{
			ll mid = l + r >> 1;
			ll val = 2 * line - mid;
			if((val + line - 1) * (mid - line) / 2 < x)
				l = mid + 1;
			else
				r = mid;
		}
		real_pos = l;
	}
	return real_pos; 
}

ll Get_val(ll hang, ll lie)
{
	if(lie > hang)
		return 2 * hang - lie;
	else
		return lie;
}

ll random(ll l, ll r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l; 
}

int main()
{
	srand(time(0));
	while(1)
	{
		n = random(1LL, 50LL);
		ll now = n;
		ll cur_line = Get_line(n);
		ll last_line = cur_line - 1;
		ll pre_sum = Query1(last_line);
		ll pre_cnt = last_line * last_line;
		ll left = n - pre_sum;
		ll cur_pos = Get_pos(left, cur_line);
		//
		ll A = cur_pos + pre_cnt;
		//
		ll cur_hang = 1, cur_lie = 1, ans = 0;
		while(now > 0)
		{
			ll cur_val = Get_val(cur_hang, cur_lie);
//			cout << ans << " " << cur_hang << " " << cur_lie << " " << cur_val << " " << n << endl;
			now -= cur_val;
			cur_lie++;
			ans++;
			if(cur_lie > 2 * cur_hang - 1)
			{
				cur_hang++;
				cur_lie = 1;
			}
		}
		ll B = ans;
		ll C = Get_pos_another(left, cur_line) + pre_cnt;
		if(A != C)
		{
			cout << "fuck!" << n << " " << A << " " << C << endl;
			break;
		}
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
