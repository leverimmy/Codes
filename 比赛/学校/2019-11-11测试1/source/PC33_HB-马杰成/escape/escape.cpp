#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
char a[510][510];
int n,m;
int val[510][510];
struct node{
	int x,y;
};
int sx,sy,ex,ey;
const int dx[7]={0,1,-1,0,0};
const int dy[7]={0,0,0,1,-1};
void init(){
	queue<node > q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='+'){
				q.push((node){i,j});			
			}
			else{
				val[i][j]=inf;
			}
		}
	}
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		q.pop();
		for(int i=1;i<=4;i++){
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			if(nx<1 || nx>n || ny<1 || ny>m) continue;
			if(val[nx][ny]>val[x][y]+1){
				val[nx][ny]=val[x][y]+1;
				q.push((node){nx,ny});
			}
		}
	}
}
int vis[505][505];
int check(int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=0;
		}
	}
	queue<node > q;
	q.push((node){sx,sy});
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		if(x==ex && y==ey) return 1;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		for(int i=1;i<=4;i++){
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			if(nx<1 || nx>n || ny<1 || ny>m) continue;
			if(val[nx][ny]>=k){
				q.push((node){nx,ny});
			}
		}		
	}
	return 0;
} 
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='V'){
				sx=i;
				sy=j;
			}
			if(a[i][j]=='J'){
				ex=i;
				ey=j;
			}
		}
	}
	init();
	int l=0,r=2000;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)==1){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",l);
}
