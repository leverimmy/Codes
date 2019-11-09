#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 200005
#define maxm 3005
#define _SIZE 2
#define mod 998244353
#define inf 100000007
namespace lib
{
	using namespace std;
	
	class fastio
	{
		private:
			#define _NUMLEN 111
			char _num[_NUMLEN],_ch;
			int _f,_head;
			
		public:
			inline void gc(char & _c) {_c=getchar();}
			template<typename _T> inline fastio & operator - (_T & _x)
			{
				_x=0;
				while(!isdigit(_ch)) _f|=_ch=='-',gc(_ch);
				while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),gc(_ch);
				_f&&(_x=-_x,_f=0);
				return *this; 
			}
			inline void pc(char _c) {putchar(_c);}
			template<typename _T> inline fastio & operator + (_T _x)
			{
				_T _k;
				if(_x==0) {pc('0'),pc(' ');return *this;}
				if(_x<0) pc('-'),_x=-_x;
				while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
				while(_head>0) pc(_num[_head]),--_head;
				pc(' ');
				return *this; 
			}
			#define endl pc('\n')
			
		fastio() {_f=0,_head=0,_ch=' ';}
	}io;
}using namespace lib;

struct t{
	int x,r;
}tt[maxn];
bool cmp(t a,t b){return a.x<b.x;}
double ans[maxn];
double p2(double a)
{
	return a*a;
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	io-n;
	for(rgi i=1;i<=n;++i)
		io-tt[i].x-tt[i].r;
	sort(tt+1,tt+1+n,cmp);
	ans[1]=tt[1].r;
	printf("%.3lf\n",ans[1]);
	for(rgi i=2;i<=n;++i)
	{
		ans[i]=p2(tt[i].x-tt[1].x)/(4*ans[1]);
		for(rgi j=i-1;j>max(1,i-100000000/n);--j)
			ans[i]=min(ans[i],p2(tt[i].x-tt[j].x)/(4*ans[j]));
		ans[i]=min(ans[i],(double)tt[i].r);
		printf("%.3lf\n",ans[i]);
	}
	return 0;
}
/*
3
0 9
8 1
13 7
*/
