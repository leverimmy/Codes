#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 100010;
int n,m;
int a[N];
void work1(){
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		int p,k;
		scanf("%d%d",&p,&k);
		int res=0;
		while(p<=n){
			p+=a[p]+k;
		}
		printf("%d\n",res);
	}
}
int ans[N];
bool vis[N];
int cnte,head[N];
struct edge{
	int to,nxt;
}e[N];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
struct sta{
	int id,dis;
};
void bfs(){
	queue<sta> q;
	q.push((sta){n, 0});
	while(!q.empty()){
		sta now=q.front();
		q.pop();
		int u=now.id;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		ans[u]=now.dis;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			q.push((sta){v, now.dis+1});
		}
	}
}
void work2(){
	for(int i=1; i<=n; i++){
		add(min(i+a[i], n), i);
	}
	bfs();
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		int p,k;
		scanf("%d%d",&p,&k);
		printf("%d\n",ans[p]);
	}
}
int main(){
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	if(n<=100){
		work1();
	}
	else{
		work2();
	}
	return 0;
}
