#include <bits/stdc++.h>
#define il inline
#define re register
#define st static
#define co const
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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>=0?(a):(-a))
#define swp(a,b) (a)^=(b)^=(a)^=(b)
#define iter iterator
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
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
	st char sta[26];
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
co int maxn=1005;
int n,k,l,r,indx,s[maxn],b[maxn*maxn];
ll ans;
signed main()
{
	fin("sequence.in");
	fout("sequence.out");
	n=rd ui(),k=rd ui(),l=rd ui(),r=rd ui();
	f1(i,n)
	{
		int x=rd ui();
		s[i]=s[i-1]+x;
		f1(j,i)
		{
			if(i-j+1>r)
				continue;
			if(i-j+1<l)
				break;
			b[++indx]=s[i]-s[j-1];
		}
	}
	sort(b+1,b+indx+1,greater<int>());
	f1(i,k)
		ans+=(ll)b[i];
	wr<ll>(ans);
	return 0;
}

