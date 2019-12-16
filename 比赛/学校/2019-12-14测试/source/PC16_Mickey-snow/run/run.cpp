#include<bits/stdc++.h>

const int MAXN = 100050;
const int MAXM = 300050;
const int MAXK = 20;

struct Edge{
	int fr,to,val;
	Edge(){}
	Edge(const int& ifr,const int& ito,const int& ival) : fr(ifr),to(ito),val(ival) {}
	
	bool operator () (const Edge& a,const Edge& comp) const { return a.val < comp.val; }
}edge[MAXM];

//sdu
int fa[MAXN];
int FindTop(const int& nowAt){
	return fa[nowAt]==nowAt ? nowAt : fa[nowAt]=FindTop(fa[nowAt]);
}
void Unity(int a,int b){
	a = FindTop(a); b = FindTop(b);
	if(a != b) fa[a] = b;
}

std::vector< std::pair<int,int> > G[MAXN];
int up[MAXN][MAXK],dis[MAXN][MAXK],depth[MAXN];
void Dfs(const std::pair<int,int>& nowAt,const int fa = 0){
	up[nowAt.first][0] = fa; dis[nowAt.first][0] = nowAt.second; depth[nowAt.first] = depth[fa] + 1;
	
	for(int i=1;i<MAXK;i++){
		up[nowAt.first][i] = up[up[nowAt.first][i-1]][i-1];
		dis[nowAt.first][i] = std::max(dis[nowAt.first][i-1], dis[up[nowAt.first][i-1]][i-1]);
	}
	
	for(int i=0;i<G[nowAt.first].size();i++)
		if(G[nowAt.first][i].first != fa) Dfs(G[nowAt.first][i], nowAt.first);
}
int Dist(int a,int b){
	int ans = 0;
	if(depth[a] < depth[b]) std::swap(a,b);
	for(int i=MAXK-1;i>=0;i--)
		if(depth[a]-(1<<i) >= depth[b]){
			ans = std::max(ans, dis[a][i]);
			a = up[a][i];
		}
	if(a == b) return ans;
	for(int i=MAXK-1;i>=0;i--)
		if(up[a][i] != up[b][i]){
			ans = std::max(ans, std::max(dis[a][i], dis[b][i]));
			a = up[a][i]; b = up[b][i];
		}
	return std::max(ans, std::max(dis[a][0], dis[b][0]));
}

signed main(void)
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	int totVertex,totEdges;
	int fr,to,val; 
	
	scanf("%d%d", &totVertex,&totEdges);
	for(int i=0;i<=totVertex;i++) fa[i] = i;
	for(int i=0;i<totEdges;i++){
		scanf("%d%d%d", &fr,&to,&val); edge[i] = Edge(fr,to,val);
	} std::sort(edge,edge+totEdges,Edge());
	
	for(int i=0;i<totEdges;i++)
		if(FindTop(edge[i].fr) != FindTop(edge[i].to)){
			Unity(edge[i].fr, edge[i].to);
			G[edge[i].fr].push_back(std::make_pair(edge[i].to, edge[i].val));
			G[edge[i].to].push_back(std::make_pair(edge[i].fr, edge[i].val));
		}
	Dfs(std::make_pair(1,0));
	
	int totQuery;
	scanf("%d", &totQuery);
	while(totQuery--){
		scanf("%d%d", &fr,&to);
		printf("%d\n", Dist(fr,to));
	}
		
	return 0;
}
