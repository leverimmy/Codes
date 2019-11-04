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
#define maxn 10010

using namespace std;

int n, k, num = 1;
int f[maxn], cnt[maxn];

struct task
{
	int s, dur;
} t[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct task a, struct task b)
{
	return a.s > b.s;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		t[i].s = read();
		t[i].dur = read();
		cnt[t[i].s]++;
	}
	sort(t + 1, t + k + 1, cmp);
	for(rgi i = n; i >= 1; i--)
	{
		if(cnt[i] == 0)
			f[i] = f[i + 1] + 1;
		else
			for(rgi j = 1; j <= cnt[i]; ++j)
			{
				f[i] = max(f[i], f[i + t[num].dur]);
				num++;
			}
	}
	printf("%d", f[1]);
	return 0;
}

