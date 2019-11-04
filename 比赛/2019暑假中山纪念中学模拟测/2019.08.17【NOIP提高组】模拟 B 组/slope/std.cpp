#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register ll
#define il inline

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll N = 200000 + 10;

ll n, P, Q;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ll my_abs(ll a)
{
	return a > 0 ? a : -a;
}

struct Fraction
{
	ll up, down;
	void Del()
	{
		ll g = gcd(up, down);
		up /= g;
		down /= g;
	}
} Base, Cur, Ans;

struct Point
{
	ll x, y;
} p[N];

il ll read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct Fraction operator - (struct Fraction a, struct Fraction b)
{
	struct Fraction res;
	res.up = a.up * b.down - a.down * b.up;
	res.down = a.down * b.down;
	res.Del();
	return res;
}

struct Fraction Abs(struct Fraction a)
{
	struct Fraction res;
	res.up = my_abs(a.up);
	res.down = my_abs(a.down);
	res.Del();
	return res;
}
bool operator < (struct Fraction a, struct Fraction b)
{
	return (long double)(a.up * 1.0 / a.down) < (long double)(b.up * 1.0 / b.down);
}

bool operator == (struct Fraction a, struct Fraction b)
{
	return a.up * b.down == a.down * b.up;
}

bool cmp(struct Point a, struct Point b)
{
	return (a.y - b.y) * Q < (a.x - b.x) * P;
}

int main()
{
	freopen("slope.in", "r", stdin);
	freopen("slope.out", "w", stdout);
	n = read(), P = read(), Q = read();
	Base.up = P, Base.down = Q;
	Base.Del();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	sort(p + 1, p + n + 1, cmp);
	for(rgi i = 2; i <= n; ++i)
	{
		Cur.up = my_abs(p[i].y - p[i - 1].y);
		Cur.down = my_abs(p[i].x - p[i - 1].x);
		Cur.Del();
		if(i == 2 || Abs(Cur - Base) < Abs(Ans - Base))
			Ans = Cur;
	}
	printf("%lld/%lld", Ans.up, Ans.down);
	return 0;
}
