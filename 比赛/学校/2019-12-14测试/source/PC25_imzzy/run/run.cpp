#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define maxm 300005
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

int n,m;
struct edge{
	int fr,to,w;
}e[maxm];
bool cmp(edge a,edge b){return a.w<b.w;}

int fa[maxn],depth[maxn],wt[maxn],cntt;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

struct edge2{
	int to,w,nxt;
}e2[maxm];
int fst[maxn],cnte;
void addedge(int fr,int to,int w)
{
	++cnte,
	e2[cnte].to=to,
	e2[cnte].w=w,
	e2[cnte].nxt=fst[fr],
	fst[fr]=cnte;
}

bool book[maxn];
void maketree()
{
	queue<int>q;
	q.push(1);
	book[1]=1;
	fa[1]=1;
	wt[1]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(rgi i=fst[t];i;i=e2[i].nxt)
			if(!book[e2[i].to])
				fa[e2[i].to]=t,
				depth[e2[i].to]=depth[t]+1,
				wt[e2[i].to]=e2[i].w,
				q.push(e2[i].to),
				book[e2[i].to]=1;
	}
//	for(rgi i=1;i<=n;++i)
//		io+i+fa[i]+wt[i],io.endl;
}

int anc[maxn][20],dist[maxn][20];
void LCAinit()
{
	for(rgi i=1;i<=n;++i)
		anc[i][0]=fa[i],
		dist[i][0]=wt[i];
	for(rgi i=1;i<20;++i)
		for(rgi j=1;j<=n;++j)
			anc[j][i]=anc[anc[j][i-1]][i-1],
			dist[j][i]=max(dist[j][i-1],dist[anc[j][i-1]][i-1]);
//	for(rgi i=1;i<=n;++i)
//	{
//		for(rgi j=0;j<20;++j)
//			io+anc[i][j];
//		io.endl;
//	}
//	for(rgi i=1;i<=n;++i)
//	{
//		for(rgi j=0;j<20;++j)
//			io+dist[i][j];
//		io.endl;
//	}
}
int lca(int x,int y)
{
	int ans=0;
	if(depth[y]>depth[x])swap(x,y);
	for(rgi i=19;i>=0;--i)
		if((1<<i)<=depth[x]-depth[y])
		{
			ans=max(ans,dist[x][i]);
			x=anc[x][i];
		}
	for(rgi i=19;i>=0;--i)
		if(anc[x][i]!=anc[y][i])
		{
			ans=max(ans,max(dist[x][i],dist[y][i]));
			x=anc[x][i],y=anc[y][i];
		}
	if(x!=y)
		ans=max(ans,max(wt[x],wt[y]));
	return ans;
}

signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int x,y,z;
	io-n-m;
	for(rgi i=1;i<=m;++i)
	{
		io-x-y-z;
		e[i]=(edge){x,y,z};
	}
	sort(e+1,e+1+m,cmp);
	for(rgi i=1;i<=n;++i)fa[i]=i;
//	cout<<"hello\n";
	for(rgi i=1;i<=n&&cntt<n-1;++i)
		if(find(e[i].fr)!=find(e[i].to))
		{
			fa[find(e[i].fr)]=find(e[i].to);
			addedge(e[i].fr,e[i].to,e[i].w);
			addedge(e[i].to,e[i].fr,e[i].w);
//			io+e[i].fr+e[i].to+e[i].w,io.endl;
			++cnte;
		}
//	cout<<"hello\n";
	maketree();
	LCAinit();
//	cout<<"hello\n";
	int p;
	io-p;
	for(rgi i=1;i<=p;++i)
	{
		io-x-y;
		io+lca(x,y),io.endl;
	}
	return 0;
}

/*
4 6
1 2 3
1 3 5
2 4 1
3 4 2
4 1 3
2 3 7
3
2 4
2 3
1 4
*/
