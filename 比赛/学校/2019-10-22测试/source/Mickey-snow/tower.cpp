#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))

const int MAXN = 1001;
const int MAXT = MAXN*MAXN;

struct Edge{
    int fr,to,cost;
    Edge(){}
    Edge(const int& ifr,const int& ito,const int& idis) : fr(ifr),to(ito),cost(idis) {}

    bool operator () (const Edge& a,const Edge& comp) const {
        return a.cost < comp.cost;
    }
}edge[MAXT];

int up[MAXN];
int FindTop(const int& nowAt){
    return up[nowAt]==nowAt ? nowAt : (up[nowAt] = FindTop(up[nowAt]));
}
bool Unity(int a,int b){
    a = FindTop(a); b = FindTop(b);
    if(a == b) return false;
    up[a] = b;
    return true;
}

signed main(void)
{
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    
    int totNums,x[MAXN],y[MAXN],totEdges=0;

    scanf("%d", &totNums);
    if(totNums <= 1){ puts("0"); return 0; }
    for(int i=0;i<totNums;++i) scanf("%d%d", x+i,y+i);

    for(int i=0;i<totNums;++i)
        for(int j=i+1;j<totNums;++j)
            edge[totEdges++] = Edge(i,j, ceil(sqr(y[i]-y[j])+sqr(x[i]-x[j])*1.0));

    //std::for_each(edge,edge+totEdges,[](const auto& it){ std::cout<<it.fr<<' '<<it.to<<' '<<it.cost<<std::endl;});

    std::sort(edge,edge+totEdges,Edge());
    for(int i=0;i<totNums;++i) up[i] = i;

    for(int i=0;true;++i)
        if(Unity(edge[i].fr, edge[i].to) && --totNums<=1){
            printf("%d\n", edge[i].cost); break;
        }
    
    return 0;
}
