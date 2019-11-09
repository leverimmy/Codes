#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 500010;
int n,k,s;
int cnte,head[N];
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
struct edge{
	int to,nxt;
}e[N<<1];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
namespace sp1{
	int lg[N],ans;
	int dep[N],f[30][N];
	void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		f[0][u]=fa;
		for(int i=1; i<=lg[dep[u]]; i++){
			f[i][u]=f[i-1][f[i-1][u]];
		}
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				dfs(v, u);
			}
		}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y]){
			swap(x, y);
		}
		while(dep[x]>dep[y]){
			x=f[lg[dep[x]-dep[y]]-1][x];
		}
		if(x==y){
			return x;
		}
		for(int i=lg[dep[x]]-1; i>=0; i--){
			if(f[i][x]!=f[i][y]){
				x=f[i][x];
				y=f[i][y];
			}
		}
		return f[0][x];
	}
}
namespace sp2{
	int ans;
	int siz[N],son[N];
	void init(int u,int fa){
		siz[u]=1;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				init(v, u);
				son[u]++;
				siz[u]+=siz[v];
			}
		}
	}
	void dfs(int u,int fa){
		ans+=siz[fa]-siz[u]+son[u];
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				dfs(v, u);
			}
		}
	}
	void work(){
		init(1, 0);
		dfs(1, 0);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	n=read();
	k=read();
	s=1;
	for(int i=1; i<n; i++){
		int u=read(),v=read();
		add(u, v);
		add(v, u);
	}
	if(n<=500){
		for(int i=1; i<=n; i++){
			sp1::lg[i]=sp1::lg[i-1]+(1<<sp1::lg[i-1] == i);
		}
		sp1::dfs(s, 0);
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				int LCA=sp1::lca(i, j);
				int len=sp1::dep[i]+sp1::dep[j]-(sp1::dep[LCA]<<1);
				sp1::ans+=len/k+(len%k!=0);
			}
		}
		printf("%d\n",sp1::ans);
	}
	else if(k==1){
		sp2::work();
	}
	return 0;
}

