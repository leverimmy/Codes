#include <bits/stdc++.h>

int n,m,T[105][105],dis[105][105];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
char G[105][105];

struct node {
	int x,y;
};node newnode(int x,int y){node nd;nd.x=x;nd.y=y;return nd;}

void bfs(){
	std::queue<node>q;
	std::memset(T,-1,sizeof(T));
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
		if (G[i][j]=='*'){T[i][j]=0;q.push(newnode(i,j));}
	while (!q.empty()){
		node u=q.front();q.pop();
		for (int i=0;i<4;++i){
			int x=u.x+dx[i],y=u.y+dy[i];
			if (x>0&&x<=n&&y>0&&y<=m&&T[x][y]==-1&&G[x][y]=='.'){
				T[x][y]=T[u.x][u.y]+1;
				q.push(newnode(x,y));
			}
		}
	}
}

void bfs2(){
	std::queue<node>q;
	std::memset(dis,-1,sizeof(dis));
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
		if (G[i][j]=='S'){dis[i][j]=0;q.push(newnode(i,j));}
	while (!q.empty()){
		node u=q.front();q.pop();
		for (int i=0;i<4;++i){
			int x=u.x+dx[i],y=u.y+dy[i];
			if (x>0&&x<=n&&y>0&&y<=m&&dis[x][y]==-1&&(G[x][y]=='.'||G[x][y]=='D')&&(T[x][y]==-1||dis[u.x][u.y]+1<T[x][y])){
				dis[x][y]=dis[u.x][u.y]+1;
				q.push(newnode(x,y));
			}
		}
	}
}

int main(){
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%s",G[i]+1);
	bfs();
	bfs2();
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
		if (G[i][j]=='D'){
			if (dis[i][j]!=-1)printf("%d",dis[i][j]);
			else printf("ORZ hzwer!!!");
			return 0;
		}
	return 0;
}
