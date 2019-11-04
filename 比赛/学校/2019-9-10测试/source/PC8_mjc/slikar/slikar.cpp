#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,sx,sy,ex,ey;
int cnt;
char a[100][100];
const int dx[5]={0,-1,1,0,0};
const int dy[5]={0,0,0,-1,1};
struct node{
	int x;
	int y;
}f[10000];
int p;
int t=0;
void go(){
	t++;
	int tt=cnt;
	for(int i=1;i<=tt;i++){
		for(int j=1;j<=4;j++){
			int nowx=dx[j]+f[i].x;
			int nowy=dy[j]+f[i].y;
			if(nowx>=1 && nowx<=n && nowy>=1 && nowy<=m){
				if(a[nowx][nowy]!='*' && a[nowx][nowy]!='X' && a[nowx][nowy]!='D'){
					a[nowx][nowy]='*';
					f[++cnt].x=nowx;
					f[cnt].y=nowy;
				}
			}
		}
	}
}
queue<node> q;

int ans=inf;
int level[100][100];
bool vis[100][100];
void run(){
	q.push(node{sx,sy});
	vis[sx][sy]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		int nowx=u.x;
		int nowy=u.y;
		if(level[nowx][nowy]==t) go(); 
		for(int i=1;i<=4;i++){
			int nx=nowx+dx[i];
			int ny=nowy+dy[i];
			if(nx==ex && ny==ey){
				ans=min(ans,level[nowx][nowy]+1);
			}
			if(a[nx][ny]=='.' && !vis[nx][ny] && nx>=1 && nx<=n && ny>=1 && ny<=m){
				vis[nx][ny]=1;
				q.push(node{nx,ny});
				level[nx][ny]=min(level[nx][ny],level[nowx][nowy]+1);
			}
		}
	}
}

int main(){
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			level[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='*'){
				f[++cnt].x=i;
				f[cnt].y=j;
			}
			if(a[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(a[i][j]=='D'){
				ex=i;
				ey=j;
			}
		}
	}
	level[sx][sy]=0;
	run();
	if(ans==inf){
		printf("ORZ hzwer!!!\n");
	}
	else
	printf("%d\n",ans);
}
