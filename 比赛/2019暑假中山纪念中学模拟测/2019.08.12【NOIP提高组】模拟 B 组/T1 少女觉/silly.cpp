#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const ll N = 100000 + 10;

ll T;
ll n, up, down, w, b;

struct GIVE
{
	ll num;
	char color;
} t[N];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void Debug()
{
	printf("%lld %lld\n", up, down);
}

void IN()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char cmd[5];
		t[i].num = read();
		scanf("%s", cmd);
		if(cmd[0] == 'B')
		{
			b += t[i].num;
			t[i].color = 'B';
		}
		else if(cmd[0] == 'W')
		{
			w += t[i].num;
			t[i].color = 'W';
		}
	}
	ll g = gcd(w, b);
	up = b / g;
	down = w / g;
}

void solve()
{
	ll cur_w = 0, cur_b = 0, ans = 0;
	if(w == 0 || b == 0)
		printf("%lld\n", w + b);
	else
	{
		for(rgi i = 1; i <= n; ++i)
		{
			if(t[i].color == 'B')
			{
				if((cur_b + t[i].num) * down > cur_w * up && (cur_w * up - cur_b * down) % down == 0) //加了会爆
				{
					ll delta = (cur_w * up - cur_b * down) / down;//取一部分出来
					ans++;
					cur_b = t[i].num - delta;
					cur_w = 0;
				}
				else
					cur_b += t[i].num;
			}
			else if(t[i].color == 'W')
			{
				if((cur_w + t[i].num) * up > cur_b * down && (cur_b * down - cur_w * up) % up == 0)//加了会爆
				{
					ll delta = (cur_b * down - cur_w * up) / up;//取一部分出来
					ans++;
					cur_b = 0;
					cur_w = t[i].num - delta;
				}
				else
					cur_w += t[i].num;
			}
		}
		printf("%lld\n", ans + cur_w + cur_b);
	}
}

int main()
{
	freopen("silly.in", "r", stdin);
	freopen("silly.out", "w", stdout);
	T = read();
	for(; T; --T)
	{
		IN();//读入
//		Debug();
		solve();//处理
		n = up = down = w = b = 0;
//		memset(t, 0, sizeof(t));
	}
	return 0;
}

