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
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
inline int read()
{
    int out=0,fh=1;
    char cc=getchar();
    if (cc=='-') 
		fh=-1;
    while (cc>'9'||cc<'0') 
		cc=getchar();
    while (cc>='0'&&cc<='9')
	{
		out=out*10+cc-'0';
		cc=getchar();
	}
    return out*fh;
}
inline void write(int x)
{
	register int i;
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
	char s[22];
	int l=0;
	while(x^0) 
	{
		s[++l]=x%10+48;
		x/=10;
	}
	for(i=l;i>=1;--i)
		putchar(s[i]);
	putchar(' ');
}
struct que
{
	int opt,k,sx,sy,tx,ty;
}que[100010];
int n,m,a[1001][1001];
int vec[100010],tot;
struct edit
{
	int k,sx,sy,tx,ty;
	edit(){}
	edit(int k,int sx,int sy,int tx,int ty):k(k),sx(sx),sy(sy),tx(tx),ty(ty){}
}seq[100010];
int len(0);
signed main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read();
	m=read();
	m=read();
	register int i,j;
	for(i=1;i<=m;i++)
	{
		#define q(p) que[i].p
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='P')
		{
			q(opt)=1;
			q(k)=read();
			q(sx)=read();
			q(sy)=read();
			q(tx)=read();
			q(ty)=read();
			q(sx)++;
			q(sy)++;
			q(tx)++;
			q(ty)++;
		}
		else if(opt[0]=='S')
		{
			q(opt)=2;
			vec[++tot]=i;
		}
		else
		{
			q(k)=read();
			q(opt)=3;
		}
		#undef q
	}
	for(i=m;i>=1;i--)
	{
		#define q(p) que[i].p
		if(q(opt)==2)
			continue;
		if(q(opt)==3)
		{
			i=vec[q(k)];
			continue;
		}
		seq[++len]=edit(q(k),q(sx),q(sy),q(tx),q(ty));
		#undef q
	}
	std::reverse(seq+1,seq+len+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=1;
	for(register int p=1;p<=len;p++)
	{
		edit S=seq[p];
		for(i=1;i+S.sx-1<=S.tx;i++)
			for(j=1;j+S.sy-1<=S.ty;j++)
				if(!((i&1)^(j&1)))
					a[i+S.sx-1][j+S.sy-1]=S.k;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			write(a[i][j]);
		putchar('\n');
	}
	return 0;
}
