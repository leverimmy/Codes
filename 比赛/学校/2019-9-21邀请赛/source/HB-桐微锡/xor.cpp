#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define int long long
using namespace std;
const int N = 100010;
const int INF = 4557430888798830399;
int t,n,m;
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
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[N];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
int dis[N];
bool vis[N];
void spfa(){
	queue<int> q;
	q.push(0);
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	vis[0]=1;
	dis[0]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u]; i!=-1; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]==INF){
				dis[v]=(dis[u]^w);
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
			else if(dis[v]!=(dis[u]^w)){
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
	return;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	t=read();
	while(t--){
		memset(head, -1, sizeof head);
		cnte=0;
		n=read();
		m=read();
		for(int i=1; i<=m; i++){
			int u=read(),v=read(),w=read();
			add(u-1, v, w);
		}
		spfa();
	}
	return 0;
}
