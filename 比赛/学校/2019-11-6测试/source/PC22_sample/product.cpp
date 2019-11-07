#include <bits/stdc++.h>
#define re register
#define sp putchar(32)
#define el putchar(10)
#define is_digit(o4) (o4>47&&o4<58)
#define is_char(o4) (o4!=10&&o4!=32)
#define ui <int>
#define ll long long
#define ld long double
#define us unsigned
#define ei else if
#define co continue
#define opr operator
#define lowbit(x) ((x)&(-(x)))
#define lch p<<1
#define rch p<<1|1
#define mx(a,b) ((a)>(b)?(a):(b))
#define mn(a,b) ((a)<(b)?(a):(b))
#define ab(a) ((a)>=0?(a):(-a))
#define sw(a,b) (a)^=(b)^=(a)^=(b)
#define itr iterator
#define pii pair<int,int>
#define mp make_pair
#define lrb lower_bound
#define upb upper_bound
#define nxp next_permutation
#define prp prev_permutation
#define gri greater<int>
#define lsi less<int>
#define mts multiset
#define mtm multimap
#define uos unordered_set
#define uom unordered_map
#define pub push_back
#define prq priority_queue
#define f0(a,b) for(re int a=0,fend=(b);a<fend;++a)
#define b0(a,b) for(re int a=(b)-1;a>=0;--a)
#define f1(a,b) for(re int a=1,fend=(b);a<=fend;++a)
#define b1(a,b) for(re int a=(b);a;--a)
#define f2(a,b,c) for(re int a=(b),fend=(c);a<=fend;++a)
#define b2(a,b,c) for(re int a=(b),fend=(c);a>=fend;--a)
#define f3(a,b,c,d) for(re int a=(b),fend=(c),gap=(d);a<=fend;a+=gap)
#define b3(a,b,c,d) for(re int a=(b),fend=(c),gap=(d);a>=fend;a-=gap)
#define fd(a) for(;a;--a)
#define ft(a) for(re int a=rd<int>();a;--a)
#define fe(a) while(!a.empty())
#define fs(a,b) for(a::iterator it=b.begin();it!=b.end();++it)
#define gr(a,b) for(re int a=fst[b];a;a=nxt[a])
#define ms(a,b) memset((a),(b),sizeof(a))
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
template<typename nm> inline nm rd()
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
template<typename nm> inline void wr(re nm o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	static char sta[26];
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
inline string rs()
{
	string o1;
	re char o2=getchar();
	while(!is_char(o2))
		o2=getchar();
	while(is_char(o2))
		o1.push_back(o2),o2=getchar();
	return o1;
}
inline void ws(string o1)
{
	re int o2=o1.size();
	f0(i,o2)
		putchar(o1[i]);
}
int n,t,ans;
struct poi
{
	int t,d;
}a[205];
//Ì°ÐÄ£¬Ì°µÄÊÇt
inline bool cmp(poi p,poi q)
{
	return ((double)p.d/(double)p.t)>((double)q.d/(double)q.t);
}
signed main()
{
	fin("product.in");
	fout("product.out");
	n=rd ui();
	f1(i,n)
		a[i].t=rd ui(),a[i].d=rd ui();
	sort(a+1,a+n+1,cmp);
	f1(i,n)
	{
		t+=a[i].t;
		ans+=a[i].d*t;
	}
	wr ui(ans);
	return 0;
}

