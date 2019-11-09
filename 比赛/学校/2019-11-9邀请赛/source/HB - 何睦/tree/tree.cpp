#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <deque>
#define NO 1000005
#define PO 2000005
#define VO 20000005
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define lln putchar('\n')
#define blk putchar(' ')
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
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	return last == '-' ? -ret : ret;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
// head

int VM, n, a[NO], book[PO], p[PO], cnt, Isp[VO], ans[NO];
bool v[PO], bn[PO];
vector<int> ap[NO];
queue<int> q;
deque<int> num[PO];
// variable

void dfs(int l, int r, int lal, int lar, int la)
{
	if (l == r)
	{
		ans[l] = la;
		return;
	}
	int laal = lal, laar = lar;
	while (lal < l)
	{
		fup (i, 0, ap[lal].size() - 1)
		{
			num[ap[lal][i]].pop_front();
			if ((--book[ap[lal][i]]) == 1)
				v[ap[lal][i]] = true, q.push(ap[lal][i]);
			else if (!book[ap[lal][i]])
				v[ap[lal][i]] = false;
		}
		lal++;
	}
	while (lar > r)
	{
		fup (i, 0, ap[lar].size() - 1)
		{
			num[ap[lar][i]].pop_back();
			if ((--book[ap[lar][i]]) == 1)
				v[ap[lal][i]] = true, q.push(ap[lar][i]);
			else if (!book[ap[lar][i]])
				v[ap[lar][i]] = false;
		}
		lar--;
	}
	while (!v[q.front()])
		q.pop();
	int p = num[q.front()].front();
	ans[p] = la;
	if (p - 1 >= l)
		dfs(l, p - 1, l, r, p);
	if (p + 1 <= r)
		dfs(p + 1, r, l, r, p);
	while (lal > laal)
	{
		lal--;
		fup (i, 0, ap[lal].size() - 1)
		{
			num[ap[lal][i]].push_front(ap[lal][i]);
			if (++book[ap[lal][i]] == 1)
				v[ap[lal][i]] = true, q.push(ap[lal][i]);
			else if (book[ap[lal][i]] == 2)
				v[ap[lal][i]] = false;
		}
	}
	while (lar < laar)
	{
		lar++;
		fup (i, 0, ap[lar].size() - 1)
		{
			num[ap[lal][i]].push_back(ap[lar][i]);
			if (++book[ap[lar][i]] == 1)
				v[ap[lal][i]] = true, q.push(ap[lar][i]);
			else if (!book[ap[lar][i]] == 2)
				v[ap[lar][i]] = false;
		}
	}
}
void init()
{
	memset(book, 0, sizeof(book));
	n = read();
	fup (i, 1, n)
	{
		ap[i].clear();
		int u = a[i] = read();
		for (int j = 1; (ll)p[j] * p[j] <= u; j++)
			if (u % p[j] == 0)
			{
				ap[i].push_back(j);
				num[j].push_back(i);
				if (++book[j] == 1)
					v[j] = true, q.push(j);
				else if (book[j] == 2)
					v[j] = false;
				while ((u /= p[j]) % p[j] == 0);
			}
		if (u != 1)
		{
			u = Isp[u];
			ap[i].push_back(u);
			num[u].push_back(i);
			if (++book[u] == 1)
				v[u] = true, q.push(u);
			else if (book[u] == 2)
				v[u] = false;
		}
	}
	dfs(1, n, 1, n, 0);
	fup (i, 1, n)
		write(ans[i]), blk;
	lln;
}
// functions

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	memset(Isp, -1, sizeof(Isp)), Isp[1] = 0;
	for (int i = 2; i <= 1e7; i++)
	{
		if (Isp[i])
			p[++cnt] = i, Isp[i] = cnt;
		for (int j = 1; j <= cnt && (ll)p[j] * i <= 1e7; j++)
		{
			Isp[p[j] * i] = 0;
			if (i % p[j] == 0)
				break;
		}
	}
	int T = read();
	while (T--)
		init();
	return 0;
}
// main
