#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=50005;
typedef long long ll;
int n,k;
ll f[N][205],g[N][205];
vector<int> G[N];
ll ans=0;
void dfs(int u,int fa){
	g[u][0]++;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
		for(int j=0;j<k;j++)
			for(int l=0;l<k;l++)
				ans+=((j+l+1+k-1)/k)*g[u][j]*g[v][l]+g[u][j]*f[v][l]+f[u][j]*g[v][l];
		for(int j=0;j<k;j++) {
			g[u][(j+1)%k]+=g[v][j];
			f[u][(j+1)%k]+=f[v][j]+((j+1)/k)*g[v][j];
		}
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		G[u].push_back(v);G[v].push_back(u);
	} 
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
