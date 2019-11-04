#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, ans, flag = 1;
int x[M], h[N], w[M];

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

struct Fraction
{
	int up, down;
	void init(){int g = gcd(up, down); up /= g, down /= g;}
} cur;

bool operator <= (struct Fraction a, struct Fraction b)
{
	if(a.down < 0)
	{
		if(b.down < 0)
		{
			return a.up * b.down <= a.down * b.up;
		}
		if(b.down > 0)
		{
			return a.up * b.down >= a.down * b.up;
		}
	}
	if(a.down > 0)
	{
		if(b.down < 0)
		{
			return a.up * b.down >= a.down * b.up;
		}
		if(b.down > 0)
		{
			return a.up * b.down <= a.down * b.up;
		}
	}
}

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("noon.in", "r", stdin);
	freopen("noon.out", "w", stdout);
	n = read(), m = read();
	memset(h, -1, sizeof(h));
	for(rgi i = 1; i <= m; ++i)
	{
		x[i] = read();
		w[i] = read();
	}
	for(rgi i = 1; i <= m; ++i)
		if(x[i] <= x[i - 1])
		{
			flag = 0;
			break;
		}
	if(flag)
	{
		ans = 0, cur.up = -1, cur.down = 1;
		for(rgi i = 1; i <= m; ++i)
		{
			h[x[i]] = w[i];
			struct Fraction tmp;
			tmp.up = h[x[i]], tmp.down = x[i];
			tmp.init();
			
			if(tmp <= cur)
				printf("%d\n", ans);
			else
			{
				cur = tmp;
				ans++;
				printf("%d\n", ans);
			}
		}
	}
	else
	{
		for(rgi i = 1; i <= m; ++i)
		{
			ans = 0, cur.up = -1, cur.down = 1;
			h[x[i]] = w[i];
			
			for(rgi j = 1; j <= n; ++j)
			{
				struct Fraction tmp;
				tmp.up = h[j], tmp.down = j;
				tmp.init();
				
				if(h[j] < 0 || tmp <= cur)
					continue;
				else
				{
//					cout << "tmp : " << tmp.up << " " << tmp.down << endl;
//					cout << "cur : " << cur.up << " " << cur.down << endl;
					ans++;
					cur = tmp;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
3 4
2 4
3 6
1 1000000
1 1

5 5
1 2
2 5
3 4
4 8
5 20

*/

