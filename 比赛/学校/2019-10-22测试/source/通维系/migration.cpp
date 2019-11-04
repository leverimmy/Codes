#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 200010;
int n,m;
bool ans[N];
int cnte,head[N];
struct edge{
	int to,nxt;
}e[N<<2];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
int fa[N];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fy]=fx;
	}
}
int a[N],root;
bool vis[N];
queue<int> q;
int main(){
	freopen("migration.in", "r", stdin);
	freopen("migration.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u, v);
		add(v, u);
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		fa[i]=i;
	}
	root=a[n];
	for(int i=n; i>=1; i--){
		int u=a[i];
		vis[u]=1;
		for(int j=head[u]; j; j=e[j].nxt){
			int v=e[j].to;
			if(vis[v]){
				merge(v, u);
			}
		}
		int fu=find(u), froot=find(root);
		if(fu!=froot){
			q.push(fu);
		}
		while(!q.empty() && find(q.front())==froot){
			q.pop();
		}
		ans[i]=q.empty();
	}
	for(int i=1; i<=n; i++){
		if(ans[i]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}

