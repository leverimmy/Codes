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
#define maxn 100010

using namespace std;

const int mod = 99999997;

int n, cnt;
int c[maxn], temp[maxn];

struct node
{
	int pos, val;
} a[maxn], b[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.val < b.val;
}

void msort(int l, int r)
{
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1, k = l;
	msort(l, mid);
	msort(mid + 1, r);
	while(i <= mid && j <= r)
	{
		if(c[i] <= c[j])
			temp[k++] = c[i++];
		else
		{
			temp[k++] = c[j++];
			cnt = (ll)(cnt + mid + 1 - i) % mod;
		}
	}
	while(i <= mid)
		temp[k++] = c[i++];
	while(j <= r)
		temp[k++] = c[j++];
	for(i = l; i <= r; i++)
		c[i] = temp[i];
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i].pos = i;
		a[i].val = read();
	}
	for(rgi i = 1; i <= n; ++i)
	{
		b[i].pos = i;
		b[i].val = read();
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
		c[b[i].pos] = a[i].pos;
	msort(1, n);
	printf("%d", cnt % mod);
	return 0;
}

