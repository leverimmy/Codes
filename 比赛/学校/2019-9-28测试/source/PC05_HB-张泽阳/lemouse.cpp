#include<bits/stdc++.h>
#define ll long long
#define rgi register int
#define maxn 1005
#define mod 998244353
#define inf 1000000007
namespace mystd
{
	#define _NUMLEN 111
	int _head;
	char _str[_NUMLEN],_cht;
	
	inline char gc() {_cht=getchar();return _cht;}
	inline void pc(char c) {putchar(c);}
	struct fastio
	{
		template<typename T> inline fastio & operator - (T & x)
		{
			x=0;
			rgi f=0;
			char ch=gc();
			while(!isdigit(ch))f=f|ch=='-',ch=gc();
			while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
			f&&(x=-x);
			return *this;
		}
		template<typename T> inline fastio & operator + (T x)
		{
			if(x==0){pc('0'),pc(' ');return *this;}
			x<0&&(pc('-'),x=-x); 
			_head=0;
			while(x>0)++_head,_str[_head]=(x%10)^48,x/=10;
			while(_head>0)pc(_str[_head]),--_head;
			pc(' ');
			return *this;
		}
	}io;
	#define endl pc('\n')
	
	#define max(a,b) (a>b?a:b)
	#define min(a,b) (a<b?a:b)
	
	inline void fr(char rd[],char wt[])
	{
		rd[0]!='-'&&freopen(rd,"r",stdin);
		wt[0]!='-'&&freopen(wt,"w",stdout);
	}
}using namespace mystd;

int n,m;
int ma[maxn][maxn],f[maxn][maxn],nxt[maxn][maxn];
int dfs(int x,int y)
{
	if(x>n||y>m)
		return inf;
	if(~f[x][y])return f[x][y];
	if(x==n&&y==m)return f[x][y]=ma[x][y]+ma[x-1][y]+ma[x][y-1];
	int res1=dfs(x+1,y),res2=dfs(x,y+1);
	if(res1<inf)
	{
		res1+=ma[x-1][y]+ma[x][y-1];
		if(nxt[x+1][y]==1)
			res1+=ma[x][y+1];
	}
	if(res2<inf)
	{
		res2+=ma[x-1][y]+ma[x][y-1];
		if(nxt[x][y+1]==2)
			res2+=ma[x+1][y];
	}
	if(res1<res2)
	{
		nxt[x][y]=1;
		return f[x][y]=res1;
	}
	if(res1>res2)
	{
		nxt[x][y]=2;
		return f[x][y]=res2;
	}
	return f[x][y]=res1;
}
int main()
{
	fr("lemouse.in","lemouse.out");
	io-n-m;
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<=m;++j)
		{
			io-ma[i][j];
			f[i][j]=-1;
		}
//	dfs(1,1);
//	endl;
//	for(rgi i=1;i<=n;++i)
//	{
//		for(rgi j=1;j<=m;++j)
//			io+f[i][j];
//		endl;
//	}
//	endl;
//	for(rgi i=1;i<=n;++i)
//	{
//		for(rgi j=1;j<=m;++j)
//			io+nxt[i][j];
//		endl;
//	}
//	endl;
	io+dfs(1,1);
	return 0;
}

/*
3 9
0 0 1 0 0 0 0 0 1 
1 1 1 1 1 1 0 1 0 
1 0 0 1 0 0 1 0 0
*/ 
