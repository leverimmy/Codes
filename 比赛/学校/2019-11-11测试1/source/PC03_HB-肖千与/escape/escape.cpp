#include<bits/stdc++.h> 
using namespace std;
const int N=505;
#define MP make_pair
#define X first 
#define Y second
typedef pair<int,int> pii;
int n,m;
char s[N][N];
int dis[N][N];
int vis[N][N];
int sx,sy,tx,ty;
queue<pii> q;
int px[]={1,-1,0,0};
int py[]={0,0,1,-1};
struct node{
	int x,y,s;
	node(int a,int b,int c){x=a,y=b,s=c;}
};

void bfs(){
	while(!q.empty()){
		pii u=q.front();q.pop();
		for(int k=0;k<4;k++){
			int nx=u.X+px[k],ny=u.Y+py[k];
			if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]) continue;
			dis[nx][ny]=dis[u.X][u.Y]+1; vis[nx][ny]=1;
			q.push(MP(nx,ny));
		}
	}
}
inline bool check(int mid){
	queue<pii> q;
	memset(vis,0,sizeof(vis));
	vis[sx][sy]=1;
	q.push(MP(sx,sy));
	while(!q.empty()){
		pii u=q.front();q.pop();
		if(u.X==tx&&u.Y==ty) return 1;
		for(int k=0;k<4;k++){
			int nx=u.X+px[k],ny=u.Y+py[k];
			if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||dis[nx][ny]<mid) continue;
			vis[nx][ny]=1;
			q.push(MP(nx,ny));
		}
	}
	return 0;
}
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='V'){
				sx=i,sy=j;
			}
			if(s[i][j]=='J'){
				tx=i,ty=j;
			}
			if(s[i][j]=='+') dis[i][j]=0,q.push(MP(i,j)),vis[i][j]=1;
		}
	}
	bfs();
	int l=0,r=dis[sx][sy],ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1; 
	}
	printf("%d",ans);
	return 0;
}
