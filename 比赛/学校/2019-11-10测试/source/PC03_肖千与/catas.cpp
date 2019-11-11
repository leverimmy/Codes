#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=70005;
int n;
vector<int> G[N];
int vis[N],deg[N],dg[N];
int res=0;
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;res++;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		dg[v]--;
		if(!dg[v]) dfs(v);
	}
}
int main(){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		while(1){
			int x=read();
			if(!x) break;
			G[x].push_back(i);
			deg[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memcpy(dg,deg,sizeof(dg));
		res=0;
		dfs(i);
		printf("%d\n",res-1);
	}
	return 0;
}
