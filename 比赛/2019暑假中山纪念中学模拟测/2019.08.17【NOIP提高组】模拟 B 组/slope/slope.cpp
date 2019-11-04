#pragma GCC optimize(2)
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register int

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int N = 200000 + 10;

ll n, P, Q;

struct node
{
	ll x, y;
} Point[N];

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
} Base, Ans, Cur;

int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct Fraction Add(struct Fraction a, struct Fraction b)
{
	struct Fraction res;
	res.up = a.up * b.down + a.down * b.up;
	res.down = a.down * b.down;
	res.Del();
	return res;
}

struct Fraction Subtract(struct Fraction a, struct Fraction b)
{
	struct Fraction res;
	res.up = a.up * b.down - a.down * b.up;
	res.down = a.down * b.down;
	res.Del();
	return res;
}

struct Fraction Mul(struct Fraction a, struct Fraction b)
{
	struct Fraction res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	res.Del();
	return res;
}

struct Fraction Divide(struct Fraction a, struct Fraction b)
{
	struct Fraction res;
	res.up = a.up * b.down;
	res.down = a.down * b.up;
	res.Del();
	return res;
}

struct Fraction Abs(struct Fraction a)
{
	struct Fraction res;
	res.up = my_abs(res.up);
	res.down = my_abs(res.down);
	res.Del();
	return res;
}

bool Greater(struct Fraction a, struct Fraction b)
{
	return a.up * b.down > a.down * b.up;
}

bool Less(struct Fraction a, struct Fraction b)
{
	return a.up * b.down < a.down * b.up;
}

int main()
{
//	freopen("slope.in", "r", stdin);
//	freopen("slope.out", "w", stdout);
	n = read(), P = read(), Q = read();
	Base.up = P, Base.down = Q;
	Base.Del();
	Ans.up = oo, Ans.down = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		Point[i].x = read();
		Point[i].y = read();
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
		{
			Cur.up = my_abs(Point[i].y - Point[j].y);
			Cur.down = my_abs(Point[i].x - Point[j].x);
			Cur.Del();
			if(Less(Abs(Subtract(Cur, Base)), Abs(Subtract(Ans, Base))))
				Ans = Cur;
		}
	Ans.Del();
	printf("%lld/%lld", Ans.up, Ans.down);
	return 0;
}

