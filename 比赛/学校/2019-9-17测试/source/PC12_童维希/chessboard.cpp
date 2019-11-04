#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210;
int n,ans;
int cnte,head[N];
struct edge{
	int to,nxt;
}e[N*N];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
char read(){
	char ch=getchar();
	while(ch!='#' && ch!='.'){
		ch=getchar();
	}
	return ch;
}
int match[N];
bool vis[N];
int dfs(int u){
	if(vis[u]){
		return 0;
	}
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(!match[v] || dfs(match[v])){
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char ch=read();
			if(ch=='.'){
				add(i, j+n);
			}
		}
	}
	for(int i=1; i<=n*2; i++){
		if(!match[i]){
			memset(vis, 0, sizeof vis);
			ans+=dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}

