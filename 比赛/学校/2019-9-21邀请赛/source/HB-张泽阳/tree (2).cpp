#include<bits/stdc++.h>
#define ll long long
#define rgi register int 
#define rgl register ll
#define maxn 100005
#define maxm 1000005
#define mod 998244353
using namespace std;

void read(rgi&x)
{
	x=0;
	rgi f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	x*=f;
}
void write(rgi x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

struct edge{
	int from,to,w;
}e[maxm];
int cnte,cntv;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int fa[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge2{
	int to,w;
}tt;
vector<edge2> e2[maxn]; 
bool book[maxn];
int dist[maxn];

void dfs(int th,int dis)
{
	if(book[th])
		return;
	dist[th]=dis;
	book[th]=1;
	for(rgi i=0;i<e2[th].size();++i)
		dfs(e2[th][i].to,max(dis,e2[th][i].w));
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	rgi n,m,from,to,w;
	read(n),read(m);
	for(;m;--m)
	{
		read(from),read(to),read(w);
		++cnte;
		e[cnte].from=from;
		e[cnte].to=to;
		e[cnte].w=w;
	}
	sort(e+1,e+1+cnte,cmp);
	for(rgi i=1;i<=n;++i)
		fa[i]=i;
	for(rgi i=1;cntv<n-1;++i)
		if(find(e[i].from)!=find(e[i].to))
		{
			fa[find(e[i].from)]=find(e[i].to);
			++cntv;
			tt.to=e[i].to;
			tt.w=e[i].w;
			e2[e[i].from].push_back(tt);
			tt.to=e[i].from;
			e2[e[i].to].push_back(tt);
		}
	dfs(1,0);
	w=0;
	for(rgi i=2;i<=n;++i)
		w+=dist[i];
	printf("%d",w);
	return 0;
}
