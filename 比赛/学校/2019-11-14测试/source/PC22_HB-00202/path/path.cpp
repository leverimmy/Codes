#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#define int long long
#define rgi register long long
#define pii pair<long long,long long>
using namespace std;
const int maxn=100005;
const int maxm=200005;
const int inf=1e9+9;
int u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm];
int n,m,q,s,dis[maxn],pairs[maxm];
bool book[maxn];
priority_queue<pii,vector<pii>, greater<pii> >que;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    cin>>n>>m>>q;
    s=1; 
    for(rgi i=1;i<=m;++i)
    {
        int p,qq,r;
        cin>>p>>qq>>r;
        if(p==qq)
        	continue;
        u[i]=p,v[i]=qq,w[i]=r;
        nxt[i]=fst[u[i]];
        fst[u[i]]=i;
        rgi j=i+m;
        u[j]=qq,v[j]=p,w[j]=r;
        nxt[j]=fst[u[j]];
        fst[u[j]]=j;
        pairs[i]=j,pairs[j]=i;
    }
    while(q--)
    {
	    int p,qq,lastw;
	    cin>>p>>qq;
	    lastw=w[p];
	    w[p]=qq,w[pairs[p]]=qq;
	    memset(book,0,sizeof(book));
		for(rgi i=1;i<=n;++i)
	        dis[i]=inf;
	    dis[s]=0;
	    que.push(make_pair(0,s));
	    while(!que.empty())
	    {
	        int x=que.top().second;
	        que.pop();
	        if(book[x])
	            continue;
	        book[x]=1;
	        for(rgi i=fst[x];i;i=nxt[i])
	            if(dis[v[i]]>dis[u[i]]+w[i])
	            {
	                dis[v[i]]=dis[u[i]]+w[i];
	                que.push(make_pair(dis[v[i]],v[i]));
	            }
	    }
	    cout<<dis[n]<<endl;
	    w[p]=lastw,w[pairs[p]]=lastw;
	}
    return 0;
}

