#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define mid ((l + r) >> 1)
#define son (k << 1)
#define g(c) c = getchar()
#define gs (c < '0' || c > '9')
#define getint() ({ int _ = 0; char g(c); while (gs) g(c); while (!gs) _ = _ * 10 + c - '0', g(c); _; })
#define r(A) A = getint()
const int inf = (int) 1e9 + 10;
using namespace std;

typedef int arr32[500010];

int f[400010][22];
arr32 rig, lef, rit, let, an, x, y, c, next, g, d;
int *q[500010];
int n, ap, cnt, tA;

int detsol(int x, int y)
{
	int t = 0;
	for (int j = 21; j >= 0; --j)
		if (f[x][j] <= y)
			t += 1 << j, x = f[x][j] + 1;
	return t;
}
int tot(int *p, int x)
{
	int t = 0;
	for (; x; x -= x & -x)
		t += p[x];
	return t;
}
int query(int *p, int x)
{
	int t = 0;
	for (; x; x -= x & -x)
		t = max(t, p[x]);
	return t;
}
void toadd(int *p, int x)
{
	for (; x <= cnt; x += x & -x)
		p[x]++;
}
void quadd(int *p, int x)
{
	int t = x;
	for (; x <= cnt; x += x & -x)
		p[x] = max(p[x], t);
}
bool cmp(int *a, int *b)  {  return *a < *b;  }
int main()
{
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);

	r(n);
	for (int i = 1; i <= n; ++i)  {
		r(x[i]), r(y[i]);
		q[++tA] = x + i;
		q[++tA] = y + i;
	}

	sort(q + 1, q + tA + 1, cmp);
	int lt = -1;
	for (int i = 1; i <= tA; ++i)
		if (lt != *q[i])
			lt = *q[i], *q[i] = ++cnt;
		else  *q[i] = cnt;

	for (int i = 1; i <= cnt + 1; ++i)
		for (int j = 0; j <= 21; ++j)  f[i][j] = inf;
	
	for (int i = 1; i <= n; ++i)
		f[x[i]][0] = min(f[x[i]][0], y[i]);

	for (int i = cnt; i; --i)  {
		f[i][0] = min(f[i + 1][0], f[i][0]); 
		for (int j = 1; f[i][j - 1] <= cnt  &&  j <= 21; ++j)  {
			f[i][j] = f[i + 1][j];
			f[i][j] = f[f[i][j - 1] + 1][j - 1];
		}
	}

	tA = 0;
	for (int i = 1; i <= n; ++i)  {
		int v = tA - tot(lef, x[i] - 1) - tot(rig, cnt - y[i]);
		if (v > 0)  continue;   //  has been cover
		int xt = query(let, x[i] - 1);
		int yt = cnt - query(rit, cnt - y[i]);
		if (detsol(xt + 1, x[i] - 1) + detsol(y[i] + 1, yt) + 1 == detsol(xt + 1, yt))  {
			an[++tA] = i;
		  toadd(lef, y[i]);  toadd(rig, cnt - x[i] + 1);
			quadd(let, y[i]);  quadd(rit, cnt - x[i] + 1);
		}
	}

	printf("%d\n", tA);
	for (int i = 1; i <= tA; ++i)
		printf("%d ", an[i]);
}
