#include<bits/stdc++.h>

template<typename T>
class Prq{
private:
    std::priority_queue<T> que,del;
public:
    Prq& Insert(const int& val){ que.push(val); return *this; }
    Prq& Del(const int& val){ del.push(val); return *this; }
    T Max(void){
        while(!que.empty() && !del.empty() && que.top()==del.top()){ que.pop(); del.pop(); }
        return que.empty() ? 0 : que.top();
    }
};

const int MAXN = 100050;

struct Edge{int to,dis; Edge(){} Edge(const int& ito,const int& idis) : to(ito),dis(idis) {} };
std::vector<Edge> G[MAXN];

bool vis[MAXN];
int upmax[MAXN],downmax[MAXN],fa[MAXN];
Prq<int> que;
void Up(const int& nowAt){
    vis[nowAt] = true;
    { Prq<int> T; std::swap(T, que); }
    que.Insert(upmax[nowAt]);
    for(int i=0;i<G[nowAt].size();i++){
        const Edge& it = G[nowAt][i];
        if(!vis[it.to])
            que.Insert(downmax[it.to] + it.dis);
    }

    for(int i=0;i<G[nowAt].size();i++){
        const Edge& it = G[nowAt][i];
        if(!vis[it.to]){
            que.Del(downmax[it.to]+it.dis);
            upmax[it.to] = it.dis + que.Max();
            que.Insert(downmax[it.to]+it.dis);
        }
    }

    for(int i=0;i<G[nowAt].size();i++){
        const Edge& it = G[nowAt][i];
        if(!vis[it.to])
            Up(it.to);
    }
}
void Down(const int& nowAt){
    vis[nowAt] = true; downmax[nowAt] = 0;
    for(int i=0;i<G[nowAt].size();i++){
        const Edge& it = G[nowAt][i];
        if(!vis[it.to]){
            Down(it.to); downmax[nowAt] = std::max(downmax[nowAt], downmax[it.to]+it.dis);
        }
    }       
}

int up[MAXN];
int FindTop(const int& nowAt){
    return up[nowAt]==nowAt ? nowAt : (up[nowAt]=FindTop(up[nowAt]));
}

signed main(void)
{
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    
    int totVertex,fr,to,val,blk,sum=0;

    scanf("%d", &totVertex);
    for(int i=0;i<=totVertex;i++) up[i] = i; blk = totVertex;
    for(int i=1;i<totVertex;i++){
        scanf("%d%d%d", &fr,&to,&val); sum += (val<<1);
        G[fr].push_back(Edge(to,val)); G[to].push_back(Edge(fr,val));
        fr = FindTop(fr); to = FindTop(to);
        if(fr != to){ up[fr] = to; --blk; }
    }
    if(blk != 1){ puts("-1"); return 0; }

    memset(vis,false,sizeof(vis)); Down(1); memset(vis,false,sizeof(vis)); Up(1);
    
    int min = INT_MAX;
    for(int i=1;i<=totVertex;i++){
        scanf("%d", &val);
        if(val == 1) min = std::min(min, sum-/*ans[i]*/std::max(downmax[i],upmax[i]));
    }
    
    if(min != INT_MAX) printf("%d\n", min);
    else puts("-1");
    
    return 0;
}
