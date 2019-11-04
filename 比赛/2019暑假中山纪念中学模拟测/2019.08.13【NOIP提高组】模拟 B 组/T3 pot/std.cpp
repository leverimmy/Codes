#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int N = 100000 + 10;

int n, m;
int a[N];

struct Seg_Tree
{
	int lc, rc;
	int max_pre, max_suf, max_ans;
	int min_pre, min_suf, min_ans;
	int min_val, sum;
} t[N << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].max_pre = max(t[p << 1].max_pre, t[p << 1].sum + t[p << 1 | 1].max_pre);
	t[p].max_suf = max(t[p << 1].max_suf + t[p << 1 | 1].sum, t[p << 1 | 1].max_suf);
	t[p].max_ans = max(t[p << 1].max_suf + t[p << 1 | 1].max_pre, max(t[p << 1].max_ans, t[p << 1 | 1].max_ans));
	t[p].min_pre = min(t[p << 1].min_pre, t[p << 1].sum + t[p << 1 | 1].min_pre);
	t[p].min_suf = min(t[p << 1].min_suf + t[p << 1 | 1].sum, t[p << 1 | 1].min_suf);
	t[p].min_ans = min(t[p << 1].min_suf + t[p << 1 | 1].min_pre, min(t[p << 1].min_ans, t[p << 1 | 1].min_ans));
	t[p].min_val = min(t[p << 1].min_val, t[p << 1 | 1].min_val);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].max_ans = t[p].max_pre = t[p].max_suf = a[l];
		t[p].min_ans = t[p].min_pre = t[p].min_suf = a[l];
		t[p].min_val = t[p].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Modify(int p, int x, int val)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].max_ans = t[p].max_pre = t[p].max_suf = val;
		t[p].min_ans = t[p].min_pre = t[p].min_suf = val;
		t[p].min_val = t[p].sum = val;
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(x <= mid)
		Modify(p << 1, x, val);
	else
		Modify(p << 1 | 1, x, val);
	Update(p);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	Build(1, 1, n);
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int pos = read(), val = read();
		Modify(1, pos, val);
		int ans1 = t[1].max_ans == t[1].sum ? t[1].sum - t[1].min_val : t[1].max_ans;
		int ans2 = t[1].sum - t[1].min_ans;
		int ans = max(ans1, ans2);
		printf("%d\n", ans);
	}
	return 0;
}

