#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 100010;
int n,k,ans;
int g[N];
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[N<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
int dfs(int u,int fa){
	int maxd=0;
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to,w=e[i].w;
		if(v!=fa){
			maxd=max(maxd, dfs(v, u)+w);
		}
	}
	return maxd;
}
signed main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	scanf("%lld",&n);
	for(int i=1; i<n; i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u, v, w);
		add(v, u, w);
		k+=w;
	}
	bool flag=0;
	for(int i=1; i<=n; i++){
		scanf("%lld",&g[i]);
		if(g[i]){
			flag=1;
		}
	}
	if(!flag){
		puts("-1");
		return 0;
	}
	for(int i=1; i<=n; i++){
		if(g[i]){
			ans=max(ans, dfs(i, 0));
		}
	}
	printf("%lld\n",k*2-ans);
	return 0;
}

