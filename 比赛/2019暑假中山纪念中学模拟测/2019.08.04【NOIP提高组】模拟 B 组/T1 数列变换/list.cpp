#include <cstdio>
#include <cstring>
#include <cctype>
#include <list>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n;
int rev[N];

struct list
{
	int val, _front, _next;
} l[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void debug()
{
	for(rgi i = l[0]._next; i != n + 1; i = l[i]._next)
		printf("%d ", l[i].val);
	puts("");
}

int main()
{
	n = read();
	for(rgi i = 0; i <= n + 1; ++i)
	{
		l[i].val = i;
		l[i]._front = i - 1;
		l[i]._next = i + 1;
	}
	for(rgi k = 2; k <= n; ++k)
	{
		int cnt = 0, flag = 0;
		for(rgi i = l[0]._next; i != n + 1; i = l[i]._next)
			rev[++cnt] = l[i].val;
		if(n % k == 1)
			flag = 1;
		for(rgi i = 1; i <= n; i += k)
		{
			if(flag && i == n)
				continue;
			int pos = rev[i];
			int before_one = l[pos]._front;
			int next_one = l[pos]._next;
			int end = min(n, ((i - 1) / k + 1) * k);
			l[before_one]._next = next_one;
			l[next_one]._front = before_one;//连到后面
			l[pos]._next = l[rev[end]]._next;
			l[l[rev[end]]._next]._front = pos;//放到后面
			l[rev[end]]._next = pos;
			l[pos]._front = rev[end];//放到后面
		}
//		debug();
	}
	for(rgi i = l[0]._next; i != n + 1; i = l[i]._next)
		printf("%d ", l[i].val);
	return 0;
}

