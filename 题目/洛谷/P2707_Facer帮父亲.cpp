#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, m, siz;
ll ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

struct node
{
	int val, b;
} h[maxn];

void push(struct node x)
{
	h[++siz].val = x.val;
	h[siz].b = x.b;
	int cur = siz;
	while(cur > 1)
	{
		if(h[cur >> 1].val < h[cur].val)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

void pop()
{
	swap(h[1], h[siz--]);
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(h[lc].val >= h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].val > h[cur].val)
			swap(h[nxt], h[cur]);
		else
			break;
		cur = nxt;
	}
}

struct node top()
{
	return h[1];
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int a;
		struct node temp;
		a = read(), temp.b = read();
		if(a > temp.b)
		{
			temp.val = a - temp.b;
			push(temp);
		}
	}
	while(m-- && siz)
	{
		struct node cur = top();
		pop();
		ans += cur.val;
		cur.val -= 2 * cur.b;
		if(cur.val <= 0)
			continue;
		push(cur);
	}
	write(ans);
	return 0;
}

