#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
struct node{
	int x,y,s;
	char mp[55][55];
}st,tmp;
struct cord{
	int x,y;
	cord(int X=0,int Y=0){x=X,y=Y;}
}c[55*55];
int n,m,ex,ey,sx,sy;
int vis[55][55];
char a[55][55];
int nx[]={1,-1,0,0},ny[]={0,0,1,-1};
queue<node> q;
inline bool check(int x,int y){
	return !(x<1||x>n||y<1||y>m||tmp.mp[x][y]=='X');
}
int main(){
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++){
			if(a[i][j]=='D') ex=i,ey=j,st.mp[i][j]='D';
			else if(a[i][j]=='S') sx=i,sy=j,st.mp[i][j]='.';
			else st.mp[i][j]=a[i][j];
		}
	}
	st.x=sx,st.y=sy,st.s=0;
	q.push(st);
	while(!q.empty()){
		node u=q.front();q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y]=1;
		if(u.x==ex&&u.y==ey){
			printf("%d",u.s);
			return 0;
		}
		tmp.s=u.s+1;
		int num=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				tmp.mp[i][j]=u.mp[i][j];
				if(tmp.mp[i][j]=='*') c[++num]=cord(i,j);
			}
		for(int i=1;i<=num;i++)
			for(int k=0;k<4;k++){
				int tx=c[i].x+nx[k],ty=c[i].y+ny[k];
				if(check(tx,ty)&&tmp.mp[tx][ty]!='D')
					tmp.mp[tx][ty]='*';
			}
		for(int k=0;k<4;k++){
			int tx=u.x+nx[k],ty=u.y+ny[k];
			if(check(tx,ty)&&tmp.mp[tx][ty]!='*') {
				tmp.x=tx,tmp.y=ty;
				q.push(tmp);
			}
		}
	}
	puts("ORZ hzwer!!!");
	return 0;
} 
