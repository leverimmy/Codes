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
#define maxn 100010

using namespace std;

int n, cnt = 1, siz;
int A[maxn], B[maxn];

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

struct node
{
	int a;
	int b;
	int val;
} h[maxn];

void push(int a, int b)
{
	int val = A[a] + B[b];
	h[++siz].a = a;
	h[siz].b = b;
	h[siz].val = val;
	int cur = siz;
	while(cur > 1)
	{
		if(h[cur].val < h[cur >> 1].val)
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
			if(h[lc].val < h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[cur].val >= h[nxt].val)
			swap(h[cur], h[nxt]);
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
	n = read();
	for(rgi i = 1; i <= n; ++i)
		A[i] = read();
	for(rgi i = 1; i <= n; ++i)
		B[i] = read(), push(i, 1);
	while(cnt <= n)
	{
		struct node temp = top();
		pop();
		write(temp.val), putchar(' '), cnt++;
		int _a = temp.a;
		int _b = temp.b;
		push(_a, _b + 1);
	}
	return 0;
}

