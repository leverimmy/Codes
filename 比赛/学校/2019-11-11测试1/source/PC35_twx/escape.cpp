#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
const int dx[4]={-1, 1, 0, 0};
const int dy[4]={0, 0, -1, 1};
char read(){
	char ch=getchar();
	while(ch!='+' && ch!='.' && ch!='V' && ch!='J'){
		ch=getchar();
	}
	return ch;
}
int n,m,sx,sy,ex,ey;
int a[N][N],d[N*N],id[N][N];
bool vis[N][N];
typedef pair<int, int> p;
void init(){
	queue<p> q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j]==0){
				vis[i][j]=1;
				q.push(mp(i, j));
			}
		}
	}
	while(!q.empty()){
		p now=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx=now.first+dx[i],ny=now.second+dy[i];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && !vis[nx][ny]){
				vis[nx][ny]=1;
				d[id[nx][ny]]=d[id[now.first][now.second]]+1;
				q.push(mp(nx, ny));
			}
		}
	}
}
int cnti,cnte,head[N*N];
struct edge{
	int to,nxt;
}e[N*N*4];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
namespace work{
	struct sta{
		int dis,id;
	};
	bool operator <(sta x,sta y){
		return x.dis > y.dis;
	}
	int vis[N*N],dis[N*N];
	bool judge(int x){
		priority_queue<sta> q;
		q.push((sta){0, id[sx][sy]});
		memset(dis, 0x3f, sizeof dis);
		memset(vis, 0, sizeof vis);
		dis[id[sx][sy]]=0;
		while(!q.empty()){
			sta now=q.top();
			q.pop();
			int u=now.id;
			if(vis[u]){
				continue;
			}
			vis[u]=1;
			for(int i=head[u]; i; i=e[i].nxt){
				int v=e[i].to;
				if(d[v]>=x && dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push((sta){dis[v], v});
				}
			}
		}
		return dis[id[ex][ey]]!=INF;
	}
}
int main(){
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			id[i][j]=++cnti;
			char ch=read();
			if(ch=='.'){
				a[i][j]=1;
			}
			else if(ch=='+'){
				a[i][j]=0;
			}
			else if(ch=='V'){
				a[i][j]=1;
				sx=i;
				sy=j;
			}
			else if(ch=='J'){
				a[i][j]=1;
				ex=i;
				ey=j;
			}
		}
	}
	init();
//	int tmp=0;
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			tmp++;
//			printf("%d ",d[tmp]);
//		}
//		puts("");
//	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=0; k<4; k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx>=1 && nx<=n && ny>=1 && nx<=m){
					add(id[i][j], id[nx][ny]);
//					printf("(%d, %d)->(%d %d)\n",i,j,nx,ny);
				}
			}
		}
	}
	int l=0,r=n+m;
	while(l<r){
		int mid=(l+r)>>1;
		if(work::judge(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(!work::judge(l)){
		l--;
	}
	printf("%d\n",l);
	return 0;
}
