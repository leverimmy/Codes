#include <iostream>
#include <cstdio>
#include <vector>

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

int n;
ll sum, sum2;
vector<int> a, b, c;

int main()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	
	io.read(n);
	
	for (int i = 1; i <= n; ++i)
	{
		int x;
		io.read(x);
		sum += x;
		sum2 += (ll) x * x;
	}
	
	while (sum)
	{
		a.push_back(sum % 10);
		sum /= 10;
	}
	
	while (sum2)
	{
		b.push_back(sum2 % 10);
		sum2 /= 10;
	}
	
	c.resize(a.size() * 2);
	
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a.size(); ++j)
		{
			c[i + j] += a[i] * a[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	}
	
	for (int i = 0; i < c.size(); ++i)
	{
		if (i < b.size()) c[i] -= b[i];
		while (c[i] < 0)
		{
			--c[i + 1];
			c[i] += 10;
		}
	}
	
	for (int i = c.size() - 1; i >= 0; --i)
	{
		if (i) c[i - 1] += (c[i] & 1) * 10;
		c[i] /= 2;
	}
	
	bool flag = false;
	for (int i = c.size() - 1; i >= 0; --i)
	{
		if (c[i]) flag = true;
		if (flag) putchar('0' + c[i]);
	}
	
	return 0;
}
