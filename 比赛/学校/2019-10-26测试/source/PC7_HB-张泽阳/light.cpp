#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define mod 1000007
#define inf 1000000007
namespace mystd
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
}using namespace mystd;

int a[maxn],n,m;
int l[maxn],r[maxn],p[maxn],v[maxn];
void solve1()
{
	int ans;
	for(rgi i=1;i<=m;++i)
	{
		ans=0;
		for(rgi j=l[i];j<=r[i];++j)
			if(a[j]%p[i]==v[i])
				++ans;
		io+ans,io.endl;
	}
}
vector<int> add[maxn];
void solve2()
{
	for(rgi i=1;i<=n;++i)
		add[a[i]%p[1]].push_back(i);
	for(rgi i=1;i<=m;++i)
	{
		int t1=lower_bound(add[v[i]].begin(),add[v[i]].end(),l[i])-add[v[i]].begin();
		int t2=upper_bound(add[v[i]].begin(),add[v[i]].end(),r[i])-add[v[i]].begin();
		io+(t2-t1),io.endl;
	}
}
signed main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	int t;
	bool sub2=1;
	io-n-m;
	for(rgi i=1;i<=n;++i)
		io-a[i];
	for(rgi i=1;i<=m;++i)
	{
		io-l[i]-r[i]-p[i]-v[i];
		if(i>1&&p[i]!=p[i-1])
			sub2=0;
	}
	if(sub2)
		solve2();
	else
		solve1();
	return 0;
}
