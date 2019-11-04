#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int fa[maxn];
int size[maxn];
int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
} 
int ret;
int vis[maxn];
void merge(int u,int v){
	int eu=find(u);
	int ev=find(v);
	if(ev!=eu){
		fa[ev]=eu;
		size[eu]+=size[ev];
	}
}
int in[maxn];
int ans[maxn];
vector <int> p[maxn];
int n,m;
int main(){
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		p[u].push_back(v);
		p[v].push_back(u);
	} 
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		size[i]=1;
	}
	int rt;
	for(int i=n;i>=1;i--){
		vis[in[i]]=1;
		for(int j=0;j<p[in[i]].size();j++){
			int to=p[in[i]][j];
			if(vis[to]) 
				merge(in[i],p[in[i]][j]);	
		}
		if(size[find(in[i])]<n-i+1) ans[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==-1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
} 
