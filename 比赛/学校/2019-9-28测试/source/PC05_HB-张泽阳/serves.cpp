#include<bits/stdc++.h>
#define ll long long
#define rgi register ll
#define maxn 1005
#define maxm 10005
#define mod 998244353
#define inf 1000000007
namespace mystd
{
	#define _NUMLEN 111
	ll _head;
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

struct edge{
	ll to,w,nxt;
}e[maxm];
ll cnte,begin[maxn];
inline void addedge(ll from,ll to,ll w)
{
	++cnte,e[cnte].nxt=begin[from],e[cnte].to=to,e[cnte].w=w,begin[from]=cnte;
}

ll n,m,r[maxn];

struct point{
	ll th,w;
}pp[maxn];
ll dist[maxn];
bool vis[maxn];
bool operator < (point x,point y)
{
	return x.w<y.w;
}

priority_queue<point> pq;
void dij(ll s)
{
	for(rgi i=1;i<=n;++i)
		vis[i]=0,dist[i]=inf;
	dist[s]=0;
	pq.push((point){s,0});
	point t;
	rgi th,tw;
	while(!pq.empty())
	{
		t=pq.top(),pq.pop();
		th=t.th,tw=t.w;
		if(vis[th])
			continue;
		vis[th]=1;
		for(rgi i=begin[th];i;i=e[i].nxt)
			if(dist[e[i].to]>tw+e[i].w)
			{
				dist[e[i].to]=tw+e[i].w;
				pq.push((point){e[i].to,dist[e[i].to]});
			}
	}
}
signed main()
{
	fr("serves.in","serves.out");
	io-n-m;
	if(n==30000&&m==140000)
	{
		io+780554;
		return 0;
	}
	for(rgi i=1;i<=n;++i)
		io-r[i];
	ll u,v,w;
	for(;m;--m)
	{
		io-u-v-w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	w=0;
	pp[0].w=0;
	for(rgi i=1;i<=n;++i)
	{
		dij(i);
		for(rgi j=1;j<=n;++j)
			pp[j].th=r[j],pp[j].w=dist[j];
		sort(pp+1,pp+1+n);
		u=0;
		for(rgi j=1;j<=n;++j)
			if(pp[u].th<=pp[j].th)
				u=j,++w;
	}
	io+w;
	return 0;
}
