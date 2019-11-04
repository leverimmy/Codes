#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 60;
const int dx[4]={1, -1, 0, 0};
const int dy[4]={0, 0, 1, -1};
int n,m;
bool a[N][N];
char read(){
	char ch=getchar();
	while(ch!='.' && ch!='*' && ch!='X' && ch!='D' && ch!='S'){
		ch=getchar();
	}
	return ch;
}
struct node{
	int x,y;
}s,t,flood;
int dis[N][N];
void bfs1(){
	queue<node> q;
	q.push(flood);
	dis[flood.x][flood.y]=0;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(a[nx][ny] && !dis[nx][ny] && nx>=1 && nx<=n && ny>=1 && ny<=m){
				dis[nx][ny]=dis[u.x][u.y]+1;
				q.push((node){nx, ny});
			}
		}
	}
}
int tim[N][N];
void bfs2(){
	queue<node> q;
	q.push(s);
	tim[s.x][s.y]=0;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx==t.x && ny==t.y){
				tim[nx][ny]=tim[u.x][u.y]+1;
				return;
			}
			if(a[nx][ny] && !tim[nx][ny] && tim[u.x][u.y]+1<dis[nx][ny] && nx>=1 && nx<=n && ny>=1 && ny<=m){
				tim[nx][ny]=tim[u.x][u.y]+1;
				q.push((node){nx, ny});
			}
		}
	}
}
int main(){
	freopen("slikar.in", "r", stdin);
	freopen("slikar.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char ch=read();
			if(ch=='X'){
				a[i][j]=0;
			}
			else if(ch=='.'){
				a[i][j]=1;
			}
			else if(ch=='*'){
				a[i][j]=0;
				flood.x=i;
				flood.y=j;
			}
			else if(ch=='S'){
				a[i][j]=1;
				s.x=i;
				s.y=j;
			}
			else if(ch=='D'){
				a[i][j]=0; 
				t.x=i;
				t.y=j;
			}
		}
	}
	bfs1();
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	bfs2();
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			printf("%d ",tim[i][j]);
//		}
//		printf("\n");
//	}
	if(!tim[t.x][t.y]){
		puts("ORZ hzwer!!!");
	}
	else{
		printf("%d\n",tim[t.x][t.y]);
	}
	return 0;
}

