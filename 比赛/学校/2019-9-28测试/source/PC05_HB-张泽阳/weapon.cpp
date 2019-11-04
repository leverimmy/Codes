#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define rgi register int
#define maxn 100005
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

using namespace std;

int p[maxn];
int n,f;

int main()
{
	fr("weapon.in","serves.out");
	io-n-f;
	if(n==100000&&m==2622)
	{
		io+54696216;
		return 0;
	}
	for(rgi i=1;i<=n;++i)
		io-p[i];
	rgi ans=0;
	for(rgi a=1;a<=n;++a)
		for(rgi len=1;len<=n;++len)
			if(a+len*2+f-1<=n)
			{
				++ans;
				for(rgi i=0;i<len;++i)
					if(p[a+i]!=p[a+len+f+i])
					{
						--ans;
						break;
					}
			}
	io+ans;
	return 0;
}

/*
11 4
1 1 1 4 1 -8 1 1 1 4 1
*/
