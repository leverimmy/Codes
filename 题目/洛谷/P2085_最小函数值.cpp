#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010

using namespace std;

int n, m, siz;
int a[maxn], b[maxn], c[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

struct node
{
	int a, b, c;
	int val, x;
} h[maxn];

int f(struct node cur)
{
	return cur.a * cur.x * cur.x + cur.b * cur.x + cur.c;
}

struct node top()
{
	return h[1];
}

void push(struct node now)
{
	h[++siz].val = now.val;
	h[siz].x = now.x;
	h[siz].a = now.a;
	h[siz].b = now.b;
	h[siz].c = now.c;
	int cur = siz;
	while(cur >= 1)
	{
		if(h[cur].val < h[cur >> 1].val)
			swap(h[cur >> 1], h[cur]);
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
			if(h[lc].val <= h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].val < h[cur].val)
		{
			swap(h[nxt], h[cur]);
			cur = nxt;
		}
		else
			break;
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		struct node temp;
		temp.a = read();
		temp.b = read();
		temp.c = read();
		temp.x = 1;
		temp.val = f(temp);
		push(temp);
	}
	for(rgi i = 1; i <= m; ++i)
	{
		struct node cur = top();
		pop();
		write(cur.val), putchar(' ');
		cur.x++;
		cur.val = f(cur);
		push(cur);
	}
	return 0;
}

