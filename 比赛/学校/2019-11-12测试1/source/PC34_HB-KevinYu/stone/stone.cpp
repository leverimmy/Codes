#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ull unsigned long long
ull INF;
ull a[4000040];
std::priority_queue<ull,std::vector<ull>,std::greater<ull> >q;
char cb[1<<17],*cs=cb,*ct=cb;
#define getc() (cs==ct&&(ct=(cs=cb)+fread(cb,1,1<<17,stdin),cs==ct)?0:*cs++)
inline void read(int &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
inline void read(ull &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
inline void write(ull x)
{
	if(x==0)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x; 
	}
	char s[101];
	int l=0;
	while(x^0) 
	{
		s[++l]=x%10+48;
		x/=10;
	}
	for(register int i=l;i>=1;--i)
		putchar(s[i]);
}
// inline write(bigInt x)
// {
	// write(x.h);
	// write(x.l);
	// putchar('\n');
// }
// struct bigInt
// {
	// ull h,l;
	// bigInt(){}
	// bigInt(ull h,ull l):h(h),l(l);
// };
// bigInt operator +(bigInt x,bigInt y)
// {
	// int xl=x.l,xh=x.h,yl=y.l,yh=y.h;
	// bigInt ans=bigInt(xh+yh,xl+yl);
	// if(ans.l<xl||ans.l<yl)
		// ans.h++;
	// return ans;
// }
// void operator +=(bigInt &x,bigInt y)
// {
	// x=x+y;
// }
// bigInt operator *(bigInt x,ull y)
// {
	// int 
// }
// bigInt operator *(bigInt x,bigInt y)
// {
	// int xl=x.l,xh=x.h,yl=y.l,yh=y.h;
	// bigInt ans=bigInt(xh*yl+yh*hl+xh*yh*bigInt(1,0),xl+yl);
	
// }
// void operator *=(bigInt &x,bigInt y)
// {
	
// }
signed main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n;
	ull ans(0);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		q.push(a[i]);
	while(q.size()>1)
	{
		ull u=q.top();
		q.pop();
		ull v=q.top();
		q.pop();
		ans+=u*v;
		q.push(u+v);
	}
	return write(ans),0;
}
