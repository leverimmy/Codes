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
#define maxn 10010

using namespace std;

int n;
int res[maxn] = {1, 1}, ans[maxn] = {1, 0}, maxans[maxn] = {1, 1};

struct node
{
	int l, r;
	ll mul;
} money[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

bool cmp(struct node a, struct node b)
{
	return a.mul < b.mul;
}

void _div(int val)
{
	int x = 0;
	memset(ans, 0, sizeof(ans));
	ans[0] = res[0];
	for(rgi i = ans[0]; i >= 1; i--)
	{
		int cur = 10 * x + res[i];
		while(cur >= val)
		{
			ans[i] = cur / val;
			cur %= val;
		}
		x = cur;
	}
	while(ans[0] > 1 && ans[ans[0]] == 0)
		ans[0]--;
}

void _mul(int val)
{
	int x = 0;
	for(rgi i = 1; i <= res[0]; ++i)
		res[i] *= val;
	for(rgi i = 1; i <= res[0]; ++i)
	{
		int cur = res[i] + x;
		res[i] = cur % 10;
		x = cur / 10;
	}
	while(x != 0)
	{
		res[0]++;
		res[res[0]] = x % 10;
		x /= 10;
	}
}

void cpy()
{
	if(ans[0] > maxans[0])
		for(rgi i = 0; i <= ans[0]; ++i)
			maxans[i] = ans[i];
	else if(ans[0] == maxans[0])
	{
		for(rgi i = ans[0]; i >= 1; i--)
			if(ans[i] > maxans[i])
			{
				for(rgi j = 0; j <= ans[0]; ++j)
					maxans[j] = ans[j];
				break;
			}
	}
}

int main()
{
	n = read();
	for(rgi i = 0; i <= n; ++i)
	{
		money[i].l = read();
		money[i].r = read();
		money[i].mul = money[i].l * money[i].r;
	}
	sort(money + 1, money + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
	{
		_mul(money[i - 1].l);
		_div(money[i].r);
		cpy();
	}
	for(rgi i = maxans[0]; i >= 1; i--)
		write(maxans[i]);
	return 0;
}

