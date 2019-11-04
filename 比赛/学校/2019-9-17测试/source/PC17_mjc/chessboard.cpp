#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int maxm=20000;
int n;
char a[110][110];
int vis[100010];
struct node{
	int to;
	int next;
}e[maxn];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int match[100000];
int dfs(int u){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v] || dfs(match[v])==1){
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}
int ans=0;
int main(){
	freopen("chessboard.in","r",stdin); 
	freopen("chessboard.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]=='.'){
				add(i,j+n);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)){
			ans++;
		}
	}
	printf("%d\n",ans); 
}
