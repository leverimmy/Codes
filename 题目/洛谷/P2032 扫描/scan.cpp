#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 2000010

using namespace std;

int n, k, cnt;
int a[maxn], out[maxn];

struct node
{
	int id, val;
};

deque <struct node> q;

il int read()
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
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		struct node tmp;
		tmp.id = i, tmp.val = a[i];
		while(!q.empty() && tmp.val > q.back().val)
			q.pop_back();
		q.push_back(tmp);
		while(!q.empty() && tmp.id - q.front().id + 1 > k)
			q.pop_front();
		cnt++;
		out[cnt] = q.front().val;
	}
	for(rgi i = k; i <= n; ++i)
		printf("%d\n", out[i]);
	return 0;
}

