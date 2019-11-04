#include <cstdio>
#include <cctype>
#include <utility>
#include <queue>
#include <cstring>
#define il inline
#define rgi register int
#define sp putchar(' ')
#define el putchar('\n')
#define pii pair<long long,int>
#define mkp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
il int ri()
{
	register int o1=0;
	register bool o2=0;
	register char o3;
	while(!isdigit(o3=getchar()))
		o2|=o3=='-';
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
il void wi(int o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
const int maxn=1e5+5;
const int maxm=2e5+5;
int n,m,s,t,u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm],pre[maxn];
ll dis[maxn];
bool book[maxn];
int stk[maxn],indx;
priority_queue<pii,vector<pii>,greater<pii> > que;
signed main()
{
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=1;i<=m;++i)
	{
		u[i]=ri(),v[i]=ri(),w[i]=ri();
		nxt[i]=fst[u[i]],fst[u[i]]=i;
		v[i+m]=u[i],u[i+m]=v[i],w[i+m]=w[i];
		nxt[i+m]=fst[u[i+m]],fst[u[i+m]]=i+m;
	}
	s=ri(),t=ri();
	memset(dis,0x7f,sizeof(dis));
	dis[s]=1;
	que.push(mkp(1ll,s));
	while(!que.empty())
	{
		int x=que.top().se;
		que.pop();
		if(book[x])
			continue;
		book[x]=1;
		for(rgi i=fst[x];i;i=nxt[i])
			if(dis[v[i]]>dis[u[i]]*(ll)w[i])
            {
                dis[v[i]]=dis[u[i]]*(ll)w[i];
                pre[v[i]]=x;
                que.push(make_pair(dis[v[i]],v[i]));
            }
	}
	for(rgi i=t;i;i=pre[i])
		stk[++indx]=i;
	for(rgi i=indx;i>=1;--i)
		wi(stk[i]),sp;
	el;
	return 0;
}

