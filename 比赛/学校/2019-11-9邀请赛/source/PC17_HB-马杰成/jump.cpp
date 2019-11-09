#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
const int maxm=1000010; 
struct node{
	int to;
	int next;
}e[maxm];
int n,m,s;
int cnt,head[maxn];
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int siz[maxn],depth[maxn],p[maxn][22];
void dfs(int u,int fa){
	depth[u]=depth[fa]+1;
	p[u][0]=fa;
	siz[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			dfs(v,u);
			siz[u]+=siz[v];
		}
	}
}

int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(depth[u]-(1<<i)>=depth[v]){
			u=p[u][i];
		}
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(p[u][i]!=p[v][i]){
			u=p[u][i];
			v=p[v][i]; 
		}
	}
	return p[u][0];
}
int f[maxn],rev[maxn];
void dfs2(int u,int fa){
	if(siz[u]>2)
		f[u]=((siz[u]-2)*(siz[u]-1))/2;
	f[u]+=siz[u]-1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			dfs2(v,u);
			rev[u]+=f[v];
		}
	}	
}
int k;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	} 
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=20;i++){
		for(int x=1;x<=n;x++){
			p[x][i]=p[p[x][i-1]][i-1];
		}
	}
	int ans=0;
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=depth[i]+depth[j]-2*depth[lca(i,j)];
				int p=t/k;
				if(p*k<t){
					p++;
				}
				ans+=p;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==1){ 
		for(int i=1;i<=n;i++){
			ans+=depth[i]*(n-1);
		}
		for(int i=1;i<=n;i++){
			ans-=(f[i]-rev[i])*depth[i]*2;
		}
		printf("%d\n",ans);
	}
}
