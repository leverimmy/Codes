#include<bits/stdc++.h>

const int MAXN = 5e5;
const int MAXM = MAXN; 

struct Edge{
	int fr,to; long long val;
	Edge(){}
	Edge(const int& ifr,const int& ito,const long long& ival) : fr(ifr),to(ito),val(ival) {}
	
	bool operator () (const Edge& a, const Edge& comp) const { return a.val < comp.val; }
}edge[MAXM];

long long ans;
bool vis[MAXN];
std::vector<Edge> G[MAXN];

void Dfs(const int& nowAt, long long val = 0LL){
	ans += val; vis[nowAt] = true;
	
	for(int i=0;i<G[nowAt].size();i++)
		if(!vis[G[nowAt][i].to])
			Dfs(G[nowAt][i].to, std::max(val,G[nowAt][i].val));
}

int up[MAXN];
int FindTop(const int& nowAt){ return up[nowAt] == nowAt ? nowAt : up[nowAt]=FindTop(up[nowAt]); }

signed main(void)
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	int totNodes,totEdges;
	int fr,to; long long val;
	
	scanf("%d%d",&totNodes,&totEdges);
	for(int i=0;i<totEdges;i++){
		scanf("%d%d%lld", &fr,&to,&val);
		edge[i] = Edge(fr,to,val);
	} std::sort(edge,edge+totEdges,Edge());
	
	for(int i=0;i<=totNodes;i++) up[i] = i;
	for(int i=0;i<totEdges;i++)
		if(FindTop(edge[i].fr) != FindTop(edge[i].to)){
			up[FindTop(edge[i].fr)] = FindTop(edge[i].to);
			G[edge[i].fr].push_back(edge[i]); G[edge[i].to].push_back(Edge(edge[i].to,edge[i].fr,edge[i].val));
		}
		
	Dfs(1);
	
	printf("%lld\n", ans);
	
	return 0;
}
