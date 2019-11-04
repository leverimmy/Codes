#include<iostream>
#include<cstdio>
#include<algorithm>
#define imax(a,b) ((a)>(b)?(a):(b))
#define imin(a,b) ((a)<(b)?(a):(b))
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
const int N = 5e5 + 551;
int to[N<<1], ne[N<<1], ed[N<<1], he[N], t[N<<1], tot, n, m, r, id, yr, f[N];
LL ans = 0;
inline void addedge(int x, int y, int z)
{
	to[++tot] = y, ed[tot] = z, ne[tot] = he[x], he[x] = tot;
	to[++tot] = x, ed[tot] = z, ne[tot] = he[y], he[y] = tot;
}
inline void up(int ro)
{
	t[ro] = imin(t[ro<<1],t[ro<<1|1]);
}
void build(int ro, int L, int R)
{
	if (L == R)
	{
		t[ro] = 1e9;
		return;
	}
	int Mid = (L + R) >> 1;
	build(ro << 1, L, Mid);
	build(ro << 1 | 1, Mid + 1, R);
	up(ro);
}
void update(int ro, int L, int R,int li,int val)
{
	if (L == R)
	{
		t[ro]=val;
		return;
	}
	int Mid = (L + R) >> 1;
	update(ro << 1, L, Mid, li, val);
	update(ro << 1 | 1, Mid + 1, R, li, val);
	up(ro);
}
int query(int ro,int L,int R)
{
	if (L == R) { t[ro]=1e9; return L;}
	int x, Mid = (L + R) >> 1;
	if (t[ro] == t[ro<<1]) x = query(ro<<1,L,Mid);
	else x = query(ro<<1|1,Mid+1,R);
	up(ro);
	return x;
}
void doit(int x)
{
	for (int i = he[x]; i; i = ne[i])
	{
		int y = to[i];
		if (f[y] > imax(f[yr],ed[i]) ) 
		{
			if (ed[i] > f[yr]) update(1,1,n,y,ed[i]);
			else f[y] = f[yr], doit(y);
		}
	}
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w",stdout);
	read(n), read(m);
	for (int i = 1; i <= m; ++i) 
	{
		int a, b, c;
		read(a), read(b), read(c);
		addedge(a, b, c);
	}
	for (int i = 2; i <= n; ++i) f[i] = 1e9;
	build(1,1,n);
	for (int i = he[1]; i; i = ne[i])
	{
		f[to[i]] = ed[i];
		update(1,1,n,to[i],f[to[i]]);
	} 
	for (;t[1]!=1e9;)
	{
		yr = query(1,1,n);
		doit(yr);
	}
	for (int i = 2; i <= n; ++i) ans += f[i];
	printf("%lld", ans);
	return 0;
}

