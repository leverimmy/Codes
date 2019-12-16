#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define mod 998244353
#define inf 1000000007
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

int n,s;
int a[maxn];
int f[maxn][25];
int dfs(int now,int who)
{
	if(f[now][who]!=-1)return f[now][who];
	int ans=(who+1)%2;
	int yuan=ans;
	if(now>=s)return (f[now][who]=who%2);
	for(rgi i=1;i<=a[who];++i)
		if(!yuan) ans=max(ans,dfs(now+i,who%n+1));
		else ans=min(ans,dfs(now+i,who%n+1));
//	io+now+who+yuan+ans,io.endl;
	return (f[now][who]=ans);
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	io-n;
	while(n)
	{
		n*=2;
		io-s;
		memset(f,-1,sizeof(f));
		for(rgi i=1;i<=n;++i)io-a[i];
//		io+a[1]+a[2];
		io+dfs(0,1);
		io.endl;
		io-n;
	}
	return 0;
}

/*
1 9 4 4
1 101 4 4
1 100 4 4
3 97 8 7 6 5 4 3
*/
