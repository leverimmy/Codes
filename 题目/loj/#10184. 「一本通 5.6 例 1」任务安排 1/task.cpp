#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 10000 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;

int n, s;
ll ans = oo;
int t[N], c[N];
ll sumt[N], sumc[N], f[N];

deque <int> q;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), s = read();
	for(rgi i = 1; i <= n; ++i)
	{
		t[i] = read();
		c[i] = read();
		sumt[i] = sumt[i - 1] + t[i];
		sumc[i] = sumc[i - 1] + c[i];
	}
	memset(f, oo, sizeof(f));
	f[0] = 0;
	//f[i] -> 前i个物品，分为一些组所用的最小代价
	for(rgi i = 1; i <= n; ++i)
	{
		while(!q.empty() && q.front().id - q.back().id + 1 > m)
			q.pop_front();
		f[i] = min(ans, (sumt[i] + s) * (sumc[i] - sum[q.front()]));
		while(!q.empty() && (sumt[i] + s) * (sumc[i] - sum[q.back()]) > 0)
			q.pop_back();
		q.push_back(i);
		//for(rgi j = 0; j < i; ++j)
		//	f[i] = min(f[i], f[j] + sumt[i] * (sumc[i] - sumc[j]) + s * (sumc[n] - sumc[j]));
		//f[j] - (sumt[i] + s) * sumc[j]
		//f[k] - (sumt[i] + s) * sumc[k]
	}
	printf("%lld", ans);
	return 0;
}

