#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,d[550][550],r[550][550],maxn=9999999;
struct ha{
	int d,r;
}a[550][550];
struct haa{
	int d,r;
}b[550][550];
bool vis[550][550];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int dfs2(int x,int y,int xx,int yy,int s){
	if(x==xx&&y==yy) return s;
	if(a[x][y].r==1) dfs2(x,y+1,xx,yy,s+1);
	if(a[x][y].d==1) dfs2(x+1,y,xx,yy,s+1);
}
void ha(){
	int k;
	cin>>k;
	while(k--){
		int x,y,xx,yy;
		cin>>x>>y>>xx>>yy;
		cout<<dfs2(x,y,xx,yy,0)<<endl;
	}
	exit(0);
}
void dfs(int x,int y,int co,int s){
    if(s==n*m){
        if(co<maxn){
            maxn=co;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++){
                    if(b[i][j].d) a[i][j].d=1;
                    if(b[i][j].r) a[i][j].r=1;
                }
            return;
        }
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx&&xx<=n&&yy&&yy<=m&&!vis[xx][yy]){
            vis[xx][yy]=1;
            if(i!=3)
                b[x][y].d=1,dfs(xx,yy,co+d[x][y],s+1),b[x][y].d=0;
            if(i!=2)
                b[x][y].r=1,dfs(xx,yy,co+r[x][y],s+1),b[x][y].r=0;
            vis[xx][yy]=0;
        }
    }
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char e,f;
			int c,dd;
			cin>>e>>c>>f>>dd;
			if(e=='D') d[i][j]=c;
			else d[i][j]=9999999,a[i][j].d=1;
			if(f=='R') r[i][j]=dd;
			else r[i][j]=9999999,a[i][j].r=1;
		}
	vis[1][1]=1;
	dfs(1,1,0,1);
	ha();
	return 0;
}