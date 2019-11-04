///tree.cpp
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=100001,maxm=500001;
int cnt,head[maxn],k;
int f[maxn];
int dis[maxn];
long long ans=0;
int n,m;
bool colour[maxn];
struct edge
{
    int from,to,w;
};
edge e[maxm],lse[maxm];
vector<int>v[maxn*2];
inline int read()
{
    register int x=0,f=0;
    register char ch=getchar();
    while(ch<'0' || ch>'9')
        f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
inline void add_edge(int from, int to, int w)
{
    cnt++;
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt].w=w;
    lse[cnt].from=from;
    lse[cnt].to=to;
    lse[cnt].w=w;
}
bool cmp(edge x, edge y)
{
	return x.w<y.w;
}
inline int getf(int x)
{
    return (f[x]==x)?x:(f[x]=getf(f[x]));
}
inline void dfs(int u, int lst, int val)
{
	vector<int>::iterator it;
	if(colour[u])
		return ;
	colour[u]=true;
	if(!(u==1 && lst==1 && val==0))
		dis[u]=max(dis[lst],val);
	for(it=v[u].begin();it!=v[u].end();it+=2)
		dfs(*it,u,*(it+1));
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read(),m=read();
    for(register int i=1,x,y,z;i<=m;i++)
    {
        x=read(),y=read(),z=read();
        add_edge(x,y,z);
    }
	for(register int i=1;i<=n;i++)
		f[i]=i;
    sort(e+1,e+m+1,cmp);
    dis[1]=0;
    for(register int i=1;i<=m;i++)
    {
        if(getf(e[i].from)==getf(e[i].to))
            continue;
		k++;
		f[e[i].from]=e[i].to;
		v[e[i].from].push_back(e[i].to);
		v[e[i].from].push_back(e[i].w);
		v[e[i].to].push_back(e[i].from);
		v[e[i].to].push_back(e[i].w); 
		if(k==n-1)
			break;
	}
	dfs(1,1,0);
    for(register int i=2;i<=n;i++)
        ans+=dis[i];
   	cout<<ans;
	getchar();getchar();
    return 0;
}
/*
8 17
1 2 6
1 3 7
1 5 4
2 3 3
3 5 5
3 4 1
4 7 6
3 6 9
4 5 2
5 6 8
4 6 8
6 8 6
7 8 3
2 4 5
2 7 4
5 8 3
4 8 4

*/
