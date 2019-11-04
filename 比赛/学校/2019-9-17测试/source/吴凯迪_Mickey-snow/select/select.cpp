#include<bits/stdc++.h>

const int MAXN = 10000;

struct Edge{
    int to,residual;
    Edge() {}
    Edge(const int& ito,const int& iRE) : to(ito),residual(iRE) {}
};
std::vector<Edge>edges; std::vector<int> G[MAXN];
void AddEdge(const int& fr,const int& to,const int& res=INT_MAX){
    G[fr].push_back(edges.size()); edges.push_back(Edge(to,res));
    G[to].push_back(edges.size()); edges.push_back(Edge(fr,0));
}

int s = MAXN-1,t = MAXN-2;
int cur[MAXN],dis[MAXN];
bool BFS(void){
    memset(dis,-1,sizeof(dis));
    std::queue<int> que; que.push(s); dis[s] = 0;

    int nowAt;
    while(!que.empty()){
	nowAt = que.front(); que.pop();
	//std::cout<<nowAt<<" "<<G[nowAt].size()<<std::endl;
	
	for(int i=0;i<G[nowAt].size();i++){
	    const Edge& it = edges[G[nowAt][i]];
	    if(it.residual>0 && dis[it.to]==-1){
		dis[it.to] = dis[nowAt] + 1;
		que.push(it.to);
	    }
	}
    } return dis[t] != -1;
}
int Dinic(const int& nowAt, int maxFlow = INT_MAX){
    if(nowAt==t || maxFlow<=0) return maxFlow;

    int deltaFlow, flow = 0;
    for(int &i=cur[nowAt]; i<G[nowAt].size();i++){
	Edge& it = edges[G[nowAt][i]];
	if(dis[nowAt]+1==dis[it.to] && 0<(deltaFlow=Dinic(it.to,std::min(maxFlow, it.residual)))){
	    flow += deltaFlow; maxFlow -= deltaFlow;
	    it.residual -= deltaFlow; edges[G[nowAt][i]^1].residual += deltaFlow;
	    if(maxFlow <= 0) break;
	}
    } return flow;
}
int MaxFlow(void){
    int flow = 0;
    while(BFS()){
	memset(cur,0,sizeof(cur));
	flow += Dinic(s);
    } return flow;
}

signed main(void)
{
    freopen("select.in","r",stdin);
    freopen("select.out","w",stdout);
    
    int totNodes,totEdges;
    int penalty,val,fr,to;
    int ans = 0;

    scanf("%d%d", &totNodes,&totEdges);
    for(int i=0;i<totNodes;i++){
	scanf("%d%d", &val,&penalty);
	AddEdge(i<<1,(i<<1)|1,penalty);
	if(val > 0){
	    ans += val;
	    AddEdge((i<<1)|1,t,val);
	} else AddEdge(s,(i<<1)|1,-val);
    }
    for(int i=0;i<totEdges;i++){
	scanf("%d%d", &fr,&to); --fr; --to;
	AddEdge((fr<<1)|1,to<<1);
    }

    printf("%d\n", ans - MaxFlow());
    
    return 0;
}
