#include <bits/stdc++.h>
#define il inline
#define re register
#define sc static
#define co const
#define st struct
#define sp putchar(32)
#define el putchar(10)
#define is_digit(o4) (o4>47&&o4<58)
#define is_char(o4) (o4!=10&&o4!=32)
#define ui <int>
#define ll long long
#define db double
#define ld long double
#define us unsigned
#define elif else if
#define cont continue
#define brk break
#define mx(a,b) ((a)>(b)?(a):(b))
#define mn(a,b) ((a)<(b)?(a):(b))
#define ab(a) ((a)>=0?(a):(-a))
#define sw(a,b) (a)^=(b)^=(a)^=(b)
#define itr iterator
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define beg begin
#define emp empty
#define clr clear
#define lrb lower_bound
#define upb upper_bound
#define ins insert
#define ers erase
#define uni unique
#define fr front
#define gri greater<int>
#define prq priority_queue
#define f0(a,b) for(re int a=0;a<(b);++a)
#define b0(a,b) for(re int a=(b)-1;a>=0;--a)
#define f1(a,b) for(re int a=1;a<=(b);++a)
#define b1(a,b) for(re int a=(b);a;--a)
#define f2(a,b,c) for(re int a=(b);a<=(c);++a)
#define b2(a,b,c) for(re int a=(b);a>=(c);--a)
#define f3(a,b,c,d) for(re int a=(b);a<=(c);a+=(d))
#define b3(a,b,c,d) for(re int a=(b);a>=(c);a-=(d))
#define fd(a) for(;a;--a)
#define ft(a) for(re int a=rd<int>();a;--a)
#define fe(a) while(!a.empty())
#define gr(a,b) for(re int a=fst[b];a;a=nxt[a])
#define ms(a,b) memset((a),(b),sizeof(a))
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
template<typename nm> il nm rd()
{
	re nm o1=0;
	re bool o2=0;
	re char o3=getchar();
	while(!is_digit(o3))
		o2|=o3=='-',o3=getchar();
	while(is_digit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
template<typename nm> il void wr(re nm o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	sc char sta[26];
	re int o5=0;
	do
	{
		re nm o2=o1/10;
		sta[++o5]=(o1-(o2<<1)-(o2<<3))^48;
		o1=o2;
	}while(o1);
	fd(o5)
		putchar(sta[o5]);
}
il int rc(char* &o1)
{
	re char o2=getchar();
	re int o5=0;
	while(!is_char(o2))
		o2=getchar();
	while(is_char(o2))
		o1[++o5]=o2,o2=getchar();
	return o5;
}
il void wc(char* o1,int len)
{
	f1(i,len)
		putchar(o1[i]);
}
il string rs()
{
	string o1;
	re char o2=getchar();
	while(!is_char(o2))
		o2=getchar();
	while(is_char(o2))
		o1.push_back(o2),o2=getchar();
	return o1;
}
il void ws(string o1)
{
	re int o2=o1.size();
	f0(i,o2)
		putchar(o1[i]);
}
const int maxn=100005;
const int maxm=maxn<<1;
int n,m,t,root,indx,u[maxm],v[maxm],fst[maxn],nxt[maxm];
int d[maxn],f[maxn][20],la;
queue ui que;
void inital()
{
	que.push(root);
	d[root]=1;
	fe(que)
	{
		int x=que.fr();
		que.pop();
		gr(i,x)
		{
			int y=v[i];
			if(d[y])
				continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			f1(j,t)
				f[y][j]=f[f[y][j-1]][j-1];
			que.push(y);
		}
	}
}
int lca(int x,int y)
{
	if(d[x]>d[y])
		sw(x,y);
	b0(i,t+1)
		if(d[f[y][i]]>=d[x])
			y=f[y][i];
	if(x==y)
		return x;
	b0(i,t+1)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
signed main()
{
	fin("lca.in");
	fout("lca.out");
	n=rd ui(),m=n-1;
	t=log(n)/log(2)+1;
	f1(i,n)
	{
		int x=rd ui();
		if(!x)
		{
			root=i;
			continue;
		}
		u[++indx]=i,v[indx]=x;
		nxt[indx]=fst[i],fst[i]=indx;
		re int j=indx+m;
		u[j]=x,v[j]=i;
		nxt[j]=fst[x],fst[x]=j;
	}
	inital();
	ft(t)
	{
		int a=rd ui()^la,b=rd ui()^la;
		la=lca(a,b);
		wr ui(la),el;
	}
	return 0;
}

