#include <bits/stdc++.h>
#define maxn 505
int n,m,dis[maxn][maxn],vis[maxn][maxn],sx,sy,tx,ty;
char G[maxn][maxn];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(){
	std::queue<std::pair<int,int> >q;
	std::memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if (G[i][j]=='+'){q.push(std::make_pair(i,j));dis[i][j]=0;}
	while (!q.empty()){
		std::pair<int,int>pii=q.front();q.pop();
		int x=pii.first,y=pii.second;
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&dis[nx][ny]==-1){
				dis[nx][ny]=dis[x][y]+1;
				q.push(std::make_pair(nx,ny));
			}
		}
	}
}

int check(int v){
//	printf("checking %d\n",v);
//	if (dis[sx][sy]<v)return 0;
	std::memset(vis,0,sizeof(vis));
	std::queue<std::pair<int,int> >q;
	q.push(std::make_pair(sx,sy));
	vis[sx][sy]=1;
	while (!q.empty()){
		std::pair<int,int>pii=q.front();q.pop();
		int x=pii.first,y=pii.second;
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&(!vis[nx][ny])&&dis[nx][ny]>=v){
				vis[nx][ny]=1;
				q.push(std::make_pair(nx,ny));
			}
		}
	}
	return vis[tx][ty];
}
	

int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",G[i]+1);
		for(int j=1;j<=m;++j){
			if (G[i][j]=='V'){sx=i;sy=j;}
			if (G[i][j]=='J'){tx=i;ty=j;}
		}
	}bfs();
	int l=0,r=n+m,ans=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){l=mid+1;ans=mid;}
		else r=mid-1;
	}printf("%d",ans);
	return 0;
}
