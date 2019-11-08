#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
const int maxm=200010;
int match[200100];
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}  
int dfs(int u){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!match[v] || dfs(match[v])==1){
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int n,m;
int ans;
int main(){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(match,0,sizeof(match));
		cnt=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			v+=n;
			add(u,v);
			add(v,u);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(dfs(i)==1) ans++;		
		}
		printf("%d\n",ans);
	}
}
