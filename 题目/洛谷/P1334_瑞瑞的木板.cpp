#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 20010

using namespace std;

int n, siz;
ll ans, h[maxn];

il void push(int val)
{
	h[++siz] = val;
	int cur = siz;
	while(cur >= 1)
	{
		if(h[cur]<h[cur >> 1])
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void pop()
{
	swap(h[1], h[siz]);
	h[siz--] = 0;
	int cur = 1;
	while((cur << 1 ) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, _next;
		if(rc <= siz)
		{
			if(h[lc] <= h[rc])
				_next = lc;
			else
				_next = rc;
		}
		else
			_next = lc;
		if(h[_next] < h[cur])
			swap(h[_next], h[cur]);
		else
			break;
		cur = _next;
	}
}

il ll top()
{
	return h[1];
}

int main()
{
	scanf("%d", &n);
	for(rgi i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		push(v);
	}
	while(siz > 1)
	{
		ll a = top();
		pop();
		ll b = top();
		pop();
		push(a + b);
		ans = ans + a + b;
	}
	printf("%lld", ans);
	return 0;
}

