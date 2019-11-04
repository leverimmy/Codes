#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define imax(a,b) (((a)>(b))?(a):(b))
#define imin(a,b) (((a)<(b))?(a):(b))
#define is(ch) (ch>='0'&&ch<='9')
#define LL long long
#define pa t[x].fa
#define lc t[x].ch[0]
#define rc t[x].ch[1]

using namespace std;

inline void read(int &x)
{
    x=0;char ch=getchar();bool f=0;
    for (;!is(ch);ch = getchar()) f |= (ch=='-');
    for (; is(ch);ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    x = f ? -x : x;
}
const int N = 250000;
int d[N], fly, n, f, a, b,T;
namespace lct{
	struct data{int ch[2],rev,sz,fa;} t[N];
	inline bool wh(int x)	{return t[pa].ch[1] == x;}
	inline bool isr(int x)	{return t[pa].ch[0] != x && t[pa].ch[1] != x;}
	inline void sc(int fa,int x,int c) {t[fa].ch[c] = x; pa = fa;}
	inline void rever(int x) {t[x].rev ^= 1, swap(lc,rc);}
	inline void update(int x) {t[x].sz = t[lc].sz + t[rc].sz + 1;}	
	inline void pushdown(int x) {
		if (t[x].rev) {
			if (lc) rever(lc);
			if (rc) rever(rc);
			t[x].rev = 0;
		}
	}
	inline void pd(int x){	if (!isr(x)) pd(pa); pushdown(x);	}
	inline void rotate(int x)
	{
		int f = pa, g = t[f].fa, c = wh(x);
		if (!isr(f)) sc(g, x, wh(f)); pa = g;
		sc(f, t[x].ch[!c], c); sc(x, f, !c); 
		update(f);
	}
	inline void splay(int x)
	{
		pd(x);
		for (;!isr(x);rotate(x))
			if (!isr(pa)) rotate(wh(x) ^ wh(pa) ? x : pa);
		update(x);
	}
	inline void access(int x)
	{
		for (int y = 0; x; y = x, x = pa) 
			splay(x), rc = y, update(x);
	}
	inline void maker(int x) {access(x), splay(x), rever(x); }
	inline void link(int x,int y) {maker(x); maker(y); pa = y;}
	inline int findroot(int x) {
		access(x); splay(x);
		while (lc) pushdown(x), x = lc;
		splay(x); return x;
	}
	inline void cut(int x, int y) {
		maker(y);
		if (findroot(x) == y && pa == y && !lc) {
			pa = t[y].ch[1] = 0; update(y);}
	}
	inline void split(int x,int y) {maker(x); access(y); splay(y); }
}
using namespace lct;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	read(n);fly = n + 1;
	for (int i = 1; i <= n; ++i)	read(d[i]);
	for (int i = 1; i <= n; ++i) link(i, i + d[i] > n ? fly : i + d[i]);
	read(T);
	while (T--)
	{
		read(a);read(f);
		split(a,fly),printf("%d\n",t[fly].sz - 1);
	} 
	return 0;
}
