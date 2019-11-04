#include<bits/stdc++.h>


constexpr auto MAXT = (50000+10)<<1;

struct Edge {
    int fr, to, residual;
    Edge() {}
    Edge(const int &ifr, const int &ito, const int &ire) : fr(ifr), to(ito), residual(ire) {}
};
std::vector<Edge> edges; std::vector<int> G[MAXT];
void AddEdge(const int &fr, const int &to, const int &re) {
    G[fr].push_back(edges.size()); edges.push_back(Edge(fr, to, re));
    G[to].push_back(edges.size()); edges.push_back(Edge(to, fr, 0));
}

int s = MAXT - 2, t = MAXT - 1, maxFlow;
int dis[MAXT], cur[MAXT];
bool BFS(void) {
    bool vis[MAXT]; memset(vis, false, sizeof(vis)); vis[s] = true;
    std::queue<int> que; que.push(s); dis[s] = 0;

    int nowAt;
    while (!que.empty()) {
	nowAt = que.front(); que.pop();
	for (int i = 0; i < G[nowAt].size(); i++) {
	    const auto &it = edges[G[nowAt][i]];
	    if (it.residual > 0 && !vis[it.to]) {
		vis[it.to] = true; dis[it.to] = dis[nowAt] + 1;
		que.push(it.to);
	    }
	}
    } return vis[t];
}
int Dfs(const int &nowAt, int maxFlow) {
    if (nowAt == t || maxFlow <= 0)return maxFlow;

    int flow = 0, deltaFlow;
    for (int &i = cur[nowAt]; i < G[nowAt].size(); i++) {
	auto &it = edges[G[nowAt][i]];
	if (dis[nowAt] + 1 == dis[it.to] && 0 < (deltaFlow = Dfs(it.to, std::min(maxFlow, it.residual)))) {
	    flow += deltaFlow; maxFlow -= deltaFlow;
	    it.residual -= deltaFlow; edges[G[nowAt][i] ^ 1].residual += deltaFlow;
	    if (maxFlow <= 0)break;
	}
    } return flow;
}
int Dinic(void) {
    while (BFS()) {
	memset(cur, 0, sizeof(cur));
	maxFlow += Dfs(s, INT_MAX);
    } return maxFlow;
}

int val[MAXT];

signed main(void)
{
    freopen("fantasy.in","r",stdin); freopen("fantasy.out","w",stdout);
    
    int totPoints,totEdges,fr,to1,to2;

    scanf("%d%d", &totPoints,&totEdges);
    for(int i=0;i<totEdges;i++){
	scanf("%d%d%d", &fr,&to1,&to2); ++val[fr];
	AddEdge(fr,to1+totPoints,1); AddEdge(fr,to2+totPoints,1);
    }

    for(int i=1;i<=totPoints;i++){
	AddEdge(s,i,val[i]); AddEdge(i+totPoints,t,val[i]);
    }

    assert(Dinic() == totEdges);
    for(int i=0;i<totEdges;i++)
	if(edges[i*4].residual == 0) putchar('0');
	else putchar('1');
    putchar('\n');
    
    return 0;
}
