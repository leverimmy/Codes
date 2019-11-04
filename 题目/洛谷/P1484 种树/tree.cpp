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
#define maxn 500010

using namespace std;

ll n, k, siz, ans;
ll l[maxn], r[maxn], a[maxn], vis[maxn];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct tree
{
	ll id, val;
} h[maxn];

void push(struct tree t)
{
	h[++siz].id = t.id;
	h[siz].val = t.val;
	ll cur = siz;
	while(cur > 1)
	{
		if(h[cur >> 1].val < h[cur].val)
			swap(h[cur >> 1], h[cur]);
		else
			break;
		cur >>= 1;
	}
}

void pop()
{
	swap(h[1], h[siz--]);
	ll cur = 1;
	while((cur << 1) <= siz)
	{
		ll lc = cur << 1, rc = lc + 1, nxt;
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

struct tree top()
{
	return h[1];
}

int main()
{
	n = read(), k = read();
	for(register ll i = 1; i <= n; ++i)
	{
		a[i] = read();
		struct tree temp;
		temp.val = a[i];
		temp.id = i;
		l[i] = i - 1;
		r[i] = i + 1;
		push(temp);
	}
	r[0] = 1;
	l[n + 1] = n;
	for(register ll i = 1; i <= k; ++i)
	{
		while(vis[top().id])pop();
		struct tree cur = top();
		ll x = cur.id;
		pop();
		if(cur.val < 0)
			break;
		ans += cur.val;
		a[x] = a[l[x]] + a[r[x]] - a[x];
		cur.val = a[x];
		vis[l[x]] = vis[r[x]] = 1;
		l[x] = l[l[x]];
		r[l[x]] = x;
		r[x] = r[r[x]];
		l[r[x]] = x;
		push(cur);
	}
	printf("%lld", ans);
	return 0;
}

