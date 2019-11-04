#include<iostream>
#include<cstdio>
#include<algorithm>
#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define is(ch) (ch>='0'&&ch<='9')
#define LL long long


using namespace std;

inline void read(int &x)
{
	x=0;char ch=getchar();bool p=0;
	for (;!is(ch);ch=getchar()) p|=ch=='-';
	for (; is(ch);ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	x=p?-x:x;
}
inline void addedge(int x, int y, int z)
{
	to[++tot] = y, ne[tot] = he[x], he[x] = tot;
	to[++tot] = x, ne[tot] = he[y], he[y] = tot;
	d[++p] = (data) {x, y, z};
}
inline void up(int ro)
{
	if (t[ro << 1].c < t[ro << 1 | 1].c) t[ro] = t[ro << 1];
	else t[ro] = t[ro << 1 | 1];
}
void build(int ro, int L, int R)
{
	if (L == R)
	{
		t[ro] = d[L];
		return;
	}
	int Mid = (L + R) >> 1;
	build(ro << 1, L, Mid);
	build(ro << 1 | 1, Mid + 1, R);
	up(ro);
}
void del(int ro,int L,int R)
{
	if (!(t[ro].a == yu.a && t[ro].b == yu.b && t[ro].c == yu.c)) return;
	if (L == R)
	{
		t[ro].c = 1e9;
		return;
	}
	int Mid = (L + R) >> 1;
	del(ro << 1, L, Mid);
	del(ro << 1 | 1, Mid + 1, R);
	up(ro);
}
int main()
{
	read(n), read(m);
	for (int i = 1; i <= m; ++i) 
	{
		read(a), read(b), read(c);
		addedge(i, a, b, c);
	}
	build(1,1,m);
	for (int i = 1; i <= m; ++i)
	{
		yu = t[1];
		del(1,1,n);
		upd(t[1])
	}
	return 0;
}
