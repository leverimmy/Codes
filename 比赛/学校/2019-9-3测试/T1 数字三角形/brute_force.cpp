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

ll Get_val(ll hang, ll lie)
{
	if(lie > hang)
		return 2 * hang - lie;
	else
		return lie;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("brute.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = read();
		ll cur_hang = 1, cur_lie = 1, ans = 0;
		while(n > 0)
		{
			ll cur_val = Get_val(cur_hang, cur_lie);
//			cout << ans << " " << cur_hang << " " << cur_lie << " " << cur_val << " " << n << endl;
			n -= cur_val;
			cur_lie++;
			ans++;
			if(cur_lie > 2 * cur_hang - 1)
			{
				cur_hang++;
				cur_lie = 1;
			}
		}
		cout << cur_hang << " " << cur_lie << " ";
		printf("%lld\n", ans);
	}
	return 0;
}

