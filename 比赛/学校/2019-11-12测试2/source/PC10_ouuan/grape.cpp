#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// #define DEBUG 1  //调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  inline char gc() {
#if DEBUG  //调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    register double tmp = 1;
    register bool sign = 0;
    x = 0;
    register char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char &c) {
#if DEBUG  //调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }
  template <class T>
  inline void write(T x) {
    if (x < 0) x = -x, push('-');  // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
  template <class T>
  inline void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

typedef pair<int, int> pii;

int n, m, t;

struct Rollback
{
	vector<int> a;
	stack<pii> c;
	
	void resize(int size, int x = 0)
	{
		a.resize(size, x);
	}
	
	void modify(int p, int x)
	{
		c.push(pii(p, a[p]));
		a[p] = x;
	}
	
	int& operator[](int p)
	{
		return a[p];
	}
	
	int size() const
	{
		return c.size();
	}
	
	void rollback(int from)
	{
		while (c.size() > from)
		{
			a[c.top().first] = c.top().second;
			c.pop();
		}
	}
} f, col, siz;

pii find(int x)
{
	if (x == f[x]) return pii(x, 0);
	pii res = find(f[x]);
	return pii(res.first, res.second ^ col[x]);
}

#define ls (cur << 1)
#define rs (cur << 1 | 1)
#define mid ((l + r) >> 1)

vector<vector<pii> > e;

void insert(int cur, int l, int r, int L, int R, pii x)
{
	if (l >= R || r <= L) return;
	if (L <= l && r <= R) e[cur].push_back(x);
	else
	{
		insert(ls, l, mid, L, R, x);
		insert(rs, mid, r, L, R, x);
	}
}

void solve(int cur, int l, int r, bool ans)
{
	int from = f.size();
	if (ans)
	{
		for (int i = 0; i < e[cur].size(); ++i)
		{
			int u = e[cur][i].first;
			int v = e[cur][i].second;
			pii fu = find(u);
			pii fv = find(v);
			if (fu.first == fv.first)
			{
				if (fu.second == fv.second)
				{
					ans = false;
					break;
				}
			}
			else
			{
				u = fu.first;
				v = fv.first;
				if (siz[u] < siz[v]) swap(u, v);
				col.modify(v, fu.second ^ fv.second ^ 1);
				siz.modify(u, siz[u] + siz[v]);
				f.modify(v, u);
			}
		}
	}
	if (l == r - 1) puts(ans ? "Yes" : "No");
	else
	{
		solve(ls, l, mid, ans);
		solve(rs, mid, r, ans);
	}
	f.rollback(from);
	col.rollback(from);
	siz.rollback(from);
}

int main()
{
	freopen("grape.in", "r", stdin);
	freopen("grape.out", "w", stdout);
	
	io.read(n);
	io.read(m);
	io.read(t);
	
	e.resize((t + 1) << 2);
	
	f.resize(n + 1);
	col.resize(n + 1, 0);
	siz.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i) f[i] = i;
	
	for (int i = 1; i <= m; ++i)
	{
		int u, v, l, r;
		io.read(u);
		io.read(v);
		io.read(l);
		io.read(r);
		insert(1, 1, t + 1, l + 1, r + 1, pii(u, v));
	}
	
	solve(1, 1, t + 1, true);
	
	return 0;
}
