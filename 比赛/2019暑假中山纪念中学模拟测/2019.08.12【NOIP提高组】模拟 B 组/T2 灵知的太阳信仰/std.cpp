#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000000 + 10;

int n, head = 1, tail;
int left[N], rev[N], pos[N], sum[N], val[N];
int f[N];

struct node
{
	int a, b;
} t[N];

multiset <int> s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		t[i].a = read();
		t[i].b = read();
	}
	for(rgi i = 1; i <= n; ++i)
	{
		left[i] = rev[t[i].a] + 1;
		rev[t[i].a] = i;
	}
	for(rgi i = 1; i <= n; ++i)
		left[i] = max(left[i - 1], left[i]);
	for(rgi i = 1; i <= n; ++i)
	{
		int k = i - 1;
		while(head < tail && pos[head + 1] < left[i])//因为有left[i]的长度限制
		{
			s.erase(s.find(sum[head]));
			head++;
		}
		while(head <= tail && t[i].b > val[tail])//踢掉菜鸡
		{
			s.erase(s.find(sum[tail]));
			k = pos[tail];
			tail--;
		}
		tail++;
		val[tail] = t[i].b;
		pos[tail] = k;
		if(head != tail)
		{
			sum[tail] = f[pos[tail]] + val[tail];
			s.insert(sum[tail]);
			s.erase(s.find(sum[head]));
		}
		sum[head] = f[left[i] - 1] + val[head];
		s.insert(sum[head]);
		f[i] = *s.begin();
	}
	printf("%d\n", f[n]);
}
