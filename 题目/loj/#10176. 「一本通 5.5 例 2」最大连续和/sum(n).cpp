#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 200000 + 10;
const int oo = 0x3f3f3f3f;

int n, m, ans = -oo;
int a[N];

struct node
{
	int val, id;
} s[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

deque <struct node> q;

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		s[i].id = i;
		s[i].val = s[i - 1].val + a[i];
	}
	for(rgi i = 1; i <= n; ++i)
	{
		struct node tmp = s[i];
		while(!q.empty() && q.back().id - q.front().id + 1 > m)	q.pop_front();
		ans = max(ans, s[i].val - q.front().val);
		while(!q.empty() && tmp.val <= q.back().val)	q.pop_back();
		q.push_back(tmp);
	}
	printf("%d", ans);
	return 0;
}

