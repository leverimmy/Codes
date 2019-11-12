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
#define ll long long
#define INF 0x3f3f3f3f
char cb[1<<17],*cs=cb,*ct=cb;
#define getc() (cs==ct&&(ct=(cs=cb)+fread(cb,1,1<<17,stdin),cs==ct)?0:*cs++)
inline void read(int &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
inline void read(ll &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
inline void write(ll x)
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
	char s[55];
	int l=0;
	while(x^0) 
	{
		s[++l]=x%10+48;
		x/=10;
	}
	for(register int i=l;i>=1;--i)
		putchar(s[i]);
	putchar('\n');
}
ll a[2][801][801],S[801][801];
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	for(int p=0;p<2;++p)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				read(a[p][i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			a[0][j][i]+=a[0][j-1][i];
			a[1][i][j]+=a[1][i][j-1];
		}
	while(m--)
	{
		int x1,x2,y1,y2;
		read(x1);
		read(y1);
		read(x2);
		read(y2);
		if(x1>x2)
			std::swap(x1,x2);
		if(y1>y2)
			std::swap(y1,y2);
		ll ans(0);
		for(int i=1;i<=n;i++)
			ans+=(a[0][x2][i]-a[0][x1-1][i])*(a[1][i][y2]-a[1][i][y1-1]);
		write(ans);
	}
	return 0;
}
