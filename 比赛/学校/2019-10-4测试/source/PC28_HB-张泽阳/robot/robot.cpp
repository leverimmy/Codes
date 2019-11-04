//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long 
#define rgi register int
#define rgl register ll
#define maxt 1000005
#define maxn 50005
#define maxm 1005
#define inf 998244353
#define mod 1000000007
namespace mystd
{
	using namespace std;
	
	class fastio
	{
		private:
			#define _NUMLEN 111
			char _ch,_num[_NUMLEN];
			int _f,_head;
			
		public:
			inline char gc() {return getchar();}
			template<typename _T> inline fastio & operator - (_T & _x)
			{
				_x=0;
				while(!isdigit(_ch))_f=_f|(_ch=='-'),_ch=gc();
				while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=gc();
				_f&&(_x=-_x,_f=0);
				return *this;
			}
			
			inline void pc(char _c) {putchar(_c);}
			template<typename _T> inline fastio & operator + (_T _x)
			{
				if(_x==0) {pc('0'),pc(' ');return *this;}
				_x<0&&(pc('-'),_x=-_x);
				while(_x>0)_f=_x/10,++_head,_num[_head]=(_x-(_f<<1)-(_f<<3))^48,_x=_f;
				while(_head>0)pc(_num[_head]),--_head;
				pc(' '),_f=0;
				return *this;
			}
			#define endl pc('\n')
		fastio() {_ch=' ',_head=0,_f=0;}
	}io;
	
	#define min(a,b) ((a)<(b)?(a):(b)) 
}using namespace mystd;

bool book[maxt];
int n,m1,m2;
int a[maxn],t[maxm],cntt;
int f1[maxn][maxm],f2[maxn][maxm],ans;
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	io-n-m1-m2;
	for(rgi i=1;i<=n;++i)
	{
		io-a[i];
		if(!book[a[i]])
			book[a[i]]=1,
			++cntt,
			t[cntt]=a[i];
	}
	sort(t+1,t+1+cntt);
	for(rgi i=1;i<=n;++i)
	{
		f2[i][0]=inf;
		for(rgi j=1;j<=cntt;++j)
		{
			f1[i][j]=f2[i-1][j];
			if(a[i]>t[j])
				f1[i][j]+=m2;
			if(a[i]<t[j])
				f1[i][j]+=m1;
			f2[i][j]=min(f1[i][j],f2[i][j-1]);
		}
	}
	ans=f2[n][cntt];
//	io+ans;
	for(rgi i=1;i<=n;++i)
	{
		f2[i][cntt+1]=inf;
		for(rgi j=cntt;j>=1;--j)
		{
			f1[i][j]=f2[i-1][j];
			if(a[i]>t[j])
				f1[i][j]+=m2;
			if(a[i]<t[j])
				f1[i][j]+=m1;
			f2[i][j]=min(f1[i][j],f2[i][j+1]);
//			io+f2[i][j];
		}
//		io.endl;
	}
	ans=min(ans,f2[n][1]); 
	io+ans;
	return 0;
}
