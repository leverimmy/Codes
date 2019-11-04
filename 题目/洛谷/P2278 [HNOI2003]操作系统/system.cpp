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
#define maxn 30010

using namespace std;

ll ans, siz;

struct sss
{
	ll id, st, dur, pri;
} h[maxn], cur;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct sss a, struct sss b)
{
	if(a.pri == b.pri)
		return a.st < b.st;
	return a.pri > b.pri;
}

void push(struct sss t)
{
	h[++siz].id = t.id;
	h[siz].st = t.st;
	h[siz].dur = t.dur;
	h[siz].pri = t.pri;
	ll cur = siz;
	while(cur > 1)
	{
		if(cmp(h[cur], h[cur >> 1]))
			swap(h[cur], h[cur >> 1]);
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
			if(cmp(h[lc], h[rc]))
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(cmp(h[nxt], h[cur]))
			swap(h[cur], h[nxt]);
		else
			break;
		cur = nxt;
	}
}

struct sss top()
{
	return h[1];
}

int main()
{
	while(scanf("%lld %lld %lld %lld", &cur.id, &cur.st, &cur.dur, &cur.pri) != EOF)
	{
		while(siz && ans + top().dur <= cur.st)
		{
			struct sss nxt = top();
			pop();
			printf("%lld %lld\n", nxt.id, ans + nxt.dur);
			ans += nxt.dur;
		}
		if(siz)
		{
			struct sss nxt = top();
			pop();
			nxt.dur = nxt.dur - cur.st + ans;
			push(nxt);
		}
		push(cur);
		ans = cur.st;
	}
	while(siz)
	{
		struct sss nxt = top();
		pop();
		ans += nxt.dur;
		printf("%lld %lld\n", nxt.id, ans);
	}
	return 0;
}

