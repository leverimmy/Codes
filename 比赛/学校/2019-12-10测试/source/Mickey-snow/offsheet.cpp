#include<bits/stdc++.h>

struct Vector2{
    int y,x;
    Vector2(){}
    Vector2(const int& iy,const int& ix) : y(iy),x(ix) {}
};
int Dist(const Vector2& a,const Vector2& b){
    return abs(a.y-b.y) + abs(a.x-b.x);
}

const int MAXN = 2500;

struct Edge{
    int fr,to,residual,cost;
    Edge(){}
    Edge(const int& ifr,const int& ito,const int& ire,const int& icost) : fr(ifr),to(ito),residual(ire),cost(icost){}
};
std::vector<Edge> edge; std::vector<int> G[MAXN];
void AddEdge(const int& fr,const int& to,const int& residual,const int& cost){
    G[fr].push_back(edge.size()); edge.push_back(Edge(fr,to,residual,cost));
    G[to].push_back(edge.size()); edge.push_back(Edge(to,fr,0,-cost));
}

int maxFlow; long long minCost;
int s=MAXN-1,t=MAXN-2;
int dis[MAXN],flow[MAXN],last[MAXN]; bool inqueue[MAXN];
bool SPFA(void){
    memset(dis,0x7f,sizeof(dis)); memset(flow,0,sizeof(flow)); memset(inqueue,false,sizeof(inqueue));
    std::queue<int> que; que.push(s); dis[s] = 0; flow[s] = INT_MAX;

    int nowAt;
    while(!que.empty()){
        nowAt = que.front(); que.pop(); inqueue[nowAt] = false;
        for(int i=0;i<G[nowAt].size();i++){
            const Edge& it = edge[G[nowAt][i]];
            if(it.residual>0 && dis[it.to]>dis[nowAt]+it.cost){
                dis[it.to] = dis[nowAt] + it.cost;
                last[it.to] = G[nowAt][i];
                flow[it.to] = std::min(flow[nowAt], it.residual);
                if(!inqueue[it.to]){ que.push(it.to); inqueue[it.to] = true; }
            }
        }
    }

    if(dis[t] >= 0) return false;
    maxFlow += flow[t]; minCost += (long long)flow[t]*dis[t];
    for(nowAt=t; nowAt!=s; nowAt=edge[last[nowAt]].fr){
        edge[last[nowAt]].residual -= flow[t];
        edge[last[nowAt]^1].residual += flow[t];
    } return true;
}
void MFMC(void){
    maxFlow = minCost = 0;
    while(SPFA());
}
                                                                             
signed main(void)
{
    freopen("offsheet.in","r",stdin);
    freopen("offsheet.out","w",stdout);
    
    Vector2 posf[MAXN],posm[MAXN];
    int totNums,y,x,val;

    scanf("%d", &totNums);
    for(int i=0;i<totNums;i++){
        scanf("%d%d%d" ,&y,&x,&val);
        posf[i] = Vector2(y,x);
        AddEdge(s,i,val,0);
    }
    for(int i=0;i<totNums;i++){
        scanf("%d%d%d", &y,&x,&val);
        posm[i] = Vector2(y,x);
        AddEdge(i+totNums,t,val,0);
    }

    for(int i=0;i<totNums;i++)
        for(int j=0;j<totNums;j++)
            AddEdge(i,j+totNums,INT_MAX,-Dist(posf[i],posm[j]));

    MFMC();
    printf("%lld\n", -minCost);
    
    return 0;
}
