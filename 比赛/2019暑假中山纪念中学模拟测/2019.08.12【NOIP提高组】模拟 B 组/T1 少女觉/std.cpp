#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const ll N = 100000 + 10;

ll T;
ll n, b, w, cur_b, cur_w, ans;

struct node
{
	ll num;
	ll color;
} t[N];

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("silly.in", "r", stdin);
	freopen("silly.out", "w", stdout);
	T = read();
	for(; T; --T)
	{
		n = b = w = cur_b = cur_w = ans = 0;
		n = read();
		for(rgi i = 1; i <= n; ++i)
		{
			char op[5];
			t[i].num = read();
			scanf("%s", op);
			if(op[0] == 'B')
			{
				t[i].color = 1;
				b += t[i].num;
			}
			else if(op[0] == 'W')
			{
				t[i].color = 0;
				w += t[i].num;
			}
		}
		if(!b || !w)
		{
			printf("%lld\n", w + b);
			continue;
		}
		for(rgi i = 1; i <= n; ++i)
		{
			ll l;
			if(t[i].color == 1)
			{
				if(cur_w * b % w != 0)
					l = -1;
				else
					l = cur_w * b / w;
				if(cur_b < l && l <= cur_b + t[i].num)
					ans++;
				cur_b += t[i].num;
			}
			else if(t[i].color == 0)
			{
				if(cur_b * w % b != 0)
					l = -1;
				else
					l = cur_b * w / b;
				if(cur_w < l && l <= cur_w + t[i].num)
					ans++;
				cur_w += t[i].num;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

