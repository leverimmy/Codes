#include <bits/stdc++.h>

using namespace std;
const int N = 200010;
const int M = 400010;
int read(){
	char ch=getchar();
	int res=0;
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int n,m,T;
struct data{
	int opt,u,v,cnt;
};
int cnte,head[N],last[M];
struct edge{
	int to,nxt,able;
}e[M];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u], 1};
	head[u]=cnte;
}
int col[N];
bool vis[N],flag=0;
void dfs(int u){
	vis[u]=1;
	if(flag){
		return;
	}
	for(int i=head[u]; ~i; i=e[i].nxt){
		int v=e[i].to,able=e[i].able;
		if(!able){
			continue;
		}
		if(vis[v]){
			if(col[v]!=col[u]^1){
				flag=1;
				return;
			}
		}
		if(col[v]==-1){
			col[v]=col[u]^1;
			dfs(v);
		}
	}
}
bool check(){
	memset(col, -1, sizeof col);
	memset(vis, 0, sizeof vis);
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			flag=0;
			col[i]=1;
			dfs(i);
			if(flag){
				return 0;
			}
		}
	}
	return 1;
}
vector<data> V[N];
int main(){
	freopen("grape.in", "r", stdin);
	freopen("grape.out", "w", stdout);
	n=read(),m=read(),T=read();
	for(int i=1; i<=m; i++){
		int u=read(),v=read(),s=read()+1,e=read()+1;
		if(s<=T){
			V[s].push_back((data){1, u, v, i});
		}
		if(e<=T){
			V[e].push_back((data){0, u, v, i});
		}
	}
	memset(head, -1, sizeof head);
	cnte=-1;
	for(int i=1; i<=T; i++){
		int siz=V[i].size();
		for(int j=0; j<siz; j++){
			if(V[i][j].opt){
				add(V[i][j].u, V[i][j].v);
				add(V[i][j].v, V[i][j].u);
				last[V[i][j].cnt]=cnte;
			}
			else{
				e[last[V[i][j].cnt]].able=0;
				e[last[V[i][j].cnt]^1].able=0;
			}
		}
		if(check()){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}

