#pragma GCC optimize (2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
#define MO 10005
#define NO 2005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (ll i = x; i <= y; i++)
#define fdn(i, x, y) for (ll i = x; i >= y; i--)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + int(ch - '0'), ch = getchar();
	if (last == '-')
		return -ans;
	return ans;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

struct node
{
	string x, nm;
	int y, m, d, h, mi, s;
}a[NO];
string nm;
int	cnt;
//variable

bool cmp(node i, node j)
{
	return i.y != j.y ? i.y < j.y : (i.m != j.m ? i.m < j.m : (i.d != j.d ? i.d < j.d : (i.h != j.h ? i.h < j.h : (i.mi != j.mi ? i.mi < j.mi : i.s < j.s))));
}
//functions

int main()
{
	freopen("qqmessage.in", "r", stdin);
	freopen("qqmessage.out", "w", stdout);
	cin >> nm;
	while (++cnt, ~scanf("%d-%d-%d %d:%d:%d ", &a[cnt].y, &a[cnt].m, &a[cnt].d, &a[cnt].h, &a[cnt].mi, &a[cnt].s))
	{
		cin >> a[cnt].nm, getchar();
		char ch = getchar();
		a[cnt].x.clear();
		while (ch != '\n')
			a[cnt].x += ch, ch = getchar();
		if (a[cnt].nm != nm)
			cnt--;
	}
	cnt--;
	sort(a + 1, a + cnt + 1, cmp);
	fup (i, 1, cnt)
		cout << a[i].x, lln;
	return 0;
}
//main
/*
Ahalei
2010-11-02 22:01:55 Ahalei 886.
2010-08-03 09:10:45 BigL What?
2010-11-02 21:45:09 Ahalei How are you?
2010-11-02 21:44:32 PGDN I'm OK!
2010-11-02 21:45:19 Ahalei what do you want to do?
2009-10-25 06:00:35 PGDN O my God!
*/
