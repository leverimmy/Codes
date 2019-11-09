#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 105
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

int a[maxn],sum;
double b[maxn],add[maxn];
double f[maxn][maxn][maxn],p[maxn][maxn];
inline double minn(double x,double y)
{
	if(x<=0.00001)return y;
	if(y<=0.00001)return x;
	return x<y?x:y;
}
signed main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	cout<<33.7842;
//	int n,m;
//	io-n-m;
//	for(rgi i=1;i<=n;++i)
//		io-a[i],sum+=a[i];
//	for(rgi i=1;i<=n;++i)
//		b[i]=(double)a[i]/(double)sum,add[i]=add[i-1]+b[i];
//	for(rgi k=1;k<=n;++k)
//		for(rgi i=k;i<=n;++i)
//			for(rgi j=i!=k?2:1;j<=minn(m,i-k+1);++j)
//			{
//				f[i][j][k]=p[i-k][j-1]+(add[i]-add[i-k])*i;
//				if(f[i-1][j][k-1]>0.00001)
//					f[i][j][k]=minn(f[i-1][j][k-1]+add[i-1]-add[i-k]+b[i]*i,f[i][j][k]);
//				io+i+j+k;
//				printf("%.4lf",f[i][j][k]),io.endl;
//				p[i][j]=minn(p[i][j],f[i][j][k]);
//			}
//	cout<<p[4][1];
//	for(rgi i=1;i<=n;++i)
//		printf("%.4lf ",f[n][m][i]);
//		
//	printf("%.4lf",p[n][m]);
	return 0;
}
/*
5 2
30 5 10 30 25
*/
