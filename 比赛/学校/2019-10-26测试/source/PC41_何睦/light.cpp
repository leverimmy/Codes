#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#define NO 300005
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret <<3) + (ret <<1) + ch  - '0', ch = getchar();
	return (last == '-') ? -ret : ret;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int n, m, b[NO], a[NO], cnt[NO], ans[NO], l, MAX;
struct Q
{
	int l, r, p, v, pos;
}q[NO];
//variable

bool cmp(Q i, Q j)
{
	return i.p < j.p;
}
bool cmp2(Q i, Q j)
{
	return ((i.l - 1) / n == (j.l - 1) / n) ? i.r < j.l : ((i.l - 1) / n < (j.l - 1) / n);
}
void work1()
{
	sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		
		if (q[i].p != q[i - 1].p)
			for (int j = 1; j <= n; j++)
				b[j] = a[j] % q[i].p;
		int cc = 0;
		for (int j = q[i].l; j <= q[i].r; j++)
			cc += (b[j] == q[i].v);
		ans[q[i].pos] = cc;
		/*
		if (q[i].p != q[i - 1].p)
		{
			memset(anss, 0, sizeof(int) * (405 * MAX));
			for (int j = 1; j <= n; j++)
				b[j] = a[j] % q[i].p, anss[b[j]][(j - 1) / l];
		}
		int nl = (q[i].l - 1) / l, nr = (q[i].l - 1) / l, cc = 0;
		for (int j = nl + 1; j <= nr - 1; j++)
			cc += anss[q[i].v][j];
		for (int j = q[i].l; j <= l * (nl + 1); j++)
			cc += (b[j] == q[i].v);
		for (int j = q[i].r; j > (nr - 1) * l; j--)
			cc += (b[j] == q[i].v);
		ans[q[i].pos] = cc;
		*/
	}
	for (int i = 1; i <= m; i++)
		write(ans[i]), putchar('\n');
}
void work2()
{
	sort(q + 1, q + m + 1, cmp2);
	int l = 1, r = 1;
	cnt[a[1] % q[1].p]++;
	for (int i = 1; i <= m; i++)
	{
		while (r < q[i].r)
			r++, cnt[a[r] % q[i].p]++;
		while (r > q[i].r)
			cnt[a[r] % q[i].p]--, r--;
		while (l > q[i].l)
			l--, cnt[a[l] % q[i].p]++;
		while (l < q[i].l)
			cnt[a[l] % q[i].p]--, l++;
//		cout << i << ':' << q[i].v << ',' << cnt[q[i].v] << ',' << l << ',' << r<< endl;
		ans[q[i].pos] = cnt[q[i].v];
	}
	for (int i = 1; i <= m; i++)
		write(ans[i]), putchar('\n');
}
//functions

int main()
{
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	n = read(), m = read(), l = sqrt(n);
	bool f = true;
	for (int i = 1; i <= n; i++)
		a[i] = read(), MAX = max(MAX, a[i]);
	MAX++;
	for (int i = 1; i <= m; i++)
	{
		q[i] = Q{ read(), read(), read(), read(), i };
		if(q[i].p >= MAX)
			q[i].p = MAX;
		f &= (i == 1 ? 1 : q[i].p == q[i - 1].p);
	}
	if (!f)
		work1();
	else
		work2();
	return 0;
} 
//main
/*
5 2
1 5 2 3 7
1 3 3 1
2 5 3 0

*/
