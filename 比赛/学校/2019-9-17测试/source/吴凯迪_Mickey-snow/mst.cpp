#include<bits/stdc++.h>

const int MAXN = 10000+50;
const double EPS = 1e-5;

struct Edge{
    int fr,to,a,b; double val;
    Edge(){}
    Edge(const int& ifr,const int& ito,const int& ia,const int& ib) : fr(ifr),to(ito),a(ia),b(ib) {}

    bool operator () (const Edge& a,const Edge& comp) const {
	return a.val < comp.val;
    }
}edge[MAXN];

int totNodes,totEdges;

//dsu
int up[MAXN];
int FindTop(const int& nowAt){ return up[nowAt]==nowAt ? nowAt : up[nowAt]=FindTop(up[nowAt]); }

bool Solve(const double& ans){
    for(int i=0;i<totEdges;i++) edge[i].val = edge[i].a-ans*edge[i].b;
    std::sort(edge,edge+totEdges,Edge());
    for(int i=0;i<totNodes;i++) up[i] = i;

    int remain=totNodes; double sum=0;
    for(int i=0;i<totEdges&&remain>1;i++)
	if(FindTop(edge[i].fr) != FindTop(edge[i].to)){
	    --remain; up[FindTop(edge[i].fr)] = edge[i].to;
	    sum += edge[i].val;
	}
    return remain==1 ? sum <= 0 : false;
}

signed main(void)
{
    freopen("mst.in","r",stdin);
    freopen("mst.out","w",stdout);
    
    int f,t,a,b;
    double fr=0,to=0,mid;

    scanf("%d%d", &totNodes,&totEdges);
    for(int i=0;i<totEdges;i++){
	scanf("%d%d%d%d", &f,&t,&a,&b);
	edge[i] = Edge(f-1,t-1,a,b); to += a;
    }

    while((to-fr) > EPS){
	mid = (fr+to)/2;
	if(Solve(mid)) to = mid;
	else fr = mid;
    }

    printf("%lf\n", (fr+to)/2);
    
    return 0;
}
