#include <bits/stdc++.h>
#define il inline
#define re register
#define sc static
#define cs const
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
#define ei else if
#define co continue
#define br break
#define swi switch
#define sys system
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
#define rev reverse
#define ins insert
#define ers erase
#define uni unique
#define fr front
#define nxp next_permutation
#define prp prev_permutation
#define gri greater<int>
#define vec vector
#define str string
#define pub push_back
#define pob pop_back
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
il str rs()
{
	str o1;
	re char o2=getchar();
	while(!is_char(o2))
		o2=getchar();
	while(is_char(o2))
		o1.push_back(o2),o2=getchar();
	return o1;
}
il void ws(str o1)
{
	re int o2=o1.size();
	f0(i,o2)
		putchar(o1[i]);
}
int n,mina,ans,tag;
vec ui a;
signed main()
{
	fin("unhappy.in");
	fout("unhappy.out");
	n=rd ui(),mina=rd ui();
	for(;n;--n)
	{
		re char ch=getchar();
		while(ch==10||ch==32)
			ch=getchar();
		int val=rd ui();
		if(ch=='I')
		{
			vec ui::itr it=lrb(a.beg(),a.end(),val);
			a.ins(it,val);
		}
		ei(ch=='A')
			f0(i,a.size())
				a[i]+=val;
		ei(ch=='S')
		{
			f0(i,a.size())
				a[i]-=val;
			fs(vec ui,a)
				if(*it<mina)
				{
					a.ers(--it);
					++ans;
				}
				else
					br;
			tag=0;
		}
		ei(ch=='F')
		{
			int sz=a.size();
			if(val>sz)
				puts("-1");
			else
				wr ui(a[sz-val]+tag),el;
		}
	}
	wr ui(ans);
	++ans;
	exit(0);
}

