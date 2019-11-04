#include<bits/stdc++.h>

const int MAXN = 1005;
const int MAXM = 100005;

struct Edge{
    int fr,to,dis;
    Edge(){}
    Edge(const int& ifr,const int& ito,const int& idis) : fr(ifr),to(ito),dis(idis) {}
};
std::vector<Edge> edges;
std::vector<int> G[MAXN];

int dist[MAXN],last[MAXN];
bool vis[MAXN],book[MAXM];

signed main(void)
{
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    
    int totVertex,totEdges;
    int fr,to,dis,nxt;

    scanf("%d%d", &totVertex,&totEdges);
    for(int i=0;i<totEdges;i++){
	scanf("%d%d%d", &fr,&to,&dis);
	G[fr].push_back(edges.size()); edges.push_back(Edge(fr,to,dis));
	G[to].push_back(edges.size()); edges.push_back(Edge(to,fr,dis));
    }

    std::fill(dist,dist+totVertex+1,INT_MAX); dist[1] = 0;
    nxt = fr = 1;
    for(int i=1;i<totVertex;i++){
	dis = INT_MAX; vis[fr = nxt] = true;
	for(int j=0;j<G[i].size();j++){
	    const Edge& it = edges[G[i][j]];
	    if(dist[it.to] >= dist[fr]+it.dis){
		dist[it.to] = dist[fr] + it.dis; last[it.to] = G[i][j];
		assert(!vis[it.to]);
	    }
	}
	for(int i=1;i<=totVertex;i++)
	    if(!vis[i] && dist[i]<dis){
		dis = dist[i]; nxt = i;
	    }

	for(int i=last[nxt];i!=-1&&!book[i];i=last[edges[i].fr])
	    book[i] = true;
    }

    long long ans = 0;
    for(int i=0;i<edges.size();i+=2)
	if(book[i] || book[i^1]) ans += edges[i].dis;

    printf("%lld\n", ans);
    
    return 0;
}
