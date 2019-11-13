#include <iostream>
#include <cstdio>
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

typedef long long ll;

int n, m;
vector<ll> f;
vector<int> pre, cnt;
vector<vector<int> > q;

int main()
{
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	pre.resize(n + 1, 0);
	cnt.resize(n + 1, 0);
	f.resize(n + 2, 0);
	q.resize(n + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		io.read(pre[i]);
		pre[i] += pre[i - 1];
	}
	
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		io.read(l);
		io.read(r);
		q[r].push_back(r);
		q[l - 1].push_back(-r);
	}
	
	for (int i = n, p = n; i >= 1; --i)
	{
		for (int j = 0; j < q[i].size(); ++j)
		{
			if (q[i][j] > 0) ++cnt[q[i][j]];
			else --cnt[-q[i][j]];
		}
		while (p >= i && !cnt[p]) --p;
		if (p < i) f[i] = f[i + 1];
		else
		{
			for (int j = i; j <= p; ++j)
			{
				f[i] = max(f[i], (ll) (pre[j] - pre[i - 1]) * (pre[j] - pre[i - 1]) + f[j + 1]);
			}
		}
	}
	
	cout << f[1];
	
	return 0;
}
