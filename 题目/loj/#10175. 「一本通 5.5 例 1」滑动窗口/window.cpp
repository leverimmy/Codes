#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const ll N = 1000000 + 10;

ll n, k;
ll out1[N], out2[N];

struct node
{
	ll val, id;
} a[N];

deque <struct node> q1, q2;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i].id = i;
		a[i].val = read();
	}
	for(rgi i = 1; i <= n; ++i)
	{
		struct node tmp = a[i];
		while(!q1.empty() && tmp.val <= q1.back().val)	q1.pop_back();
		q1.push_back(tmp);
		while(!q1.empty() && q1.back().id - q1.front().id + 1 > k)	q1.pop_front();
		out1[i] = q1.front().val;
		while(!q2.empty() && tmp.val >= q2.back().val)	q2.pop_back();
		q2.push_back(tmp);
		while(!q2.empty() && q2.back().id - q2.front().id + 1 > k)	q2.pop_front();
		out2[i] = q2.front().val;
	}
	for(rgi i = k; i <= n; ++i)
		printf("%lld ", out1[i]);
	puts("");
	for(rgi i = k; i <= n; ++i)
		printf("%lld ", out2[i]);
	return 0;
}

