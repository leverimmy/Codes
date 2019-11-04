#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1000010;
const int maxm=8000010;
int a[1010][1010];
int sum[1010][1010];
int n,m;
const int dx[5]={0,-1,0,0,1};
const int dy[5]={0,0,-1,1,0};
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v,int ww){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=ww;
	head[u]=cnt;
}
int dis[maxn],vis[maxn];
struct pp{
	int ind;
	int d;
};
bool operator < (const pp &a,const pp &b){
	return a.d>b.d;
}
priority_queue<pp> pq;
void dij(){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	pq.push((pp){1,0});
	while(pq.size()){
		int u=pq.top().ind;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				pq.push((pp){v,dis[v]});
			}
		}
	}
} 
int f[1010][1010][3];
int main(){
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j][1]=f[i][j][2]=inf;
			for(int k=1;k<=4;k++){
				int nowx=i+dx[k];
				int nowy=j+dy[k];
				if(nowx<1 || nowx>n || nowy<1 || nowy>m) continue;
				sum[i][j]+=a[nowx][nowy];
			}
		}
	}
	f[1][1][1]=f[1][1][2]=sum[1][1]+a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=2;k++){
				int nowx=i+dx[k];
				int nowy=j+dy[k];
				if(nowx<1 || nowx>n || nowy<1 || nowy>m) continue;
				if(k==1){
					f[i][j][1]=min(f[nowx][nowy][1]+sum[i][j]-a[i-1][j],f[i][j][1]);
					f[i][j][1]=min(f[nowx][nowy][2]+sum[i][j]-a[i-1][j]-a[i][j-1],f[i][j][1]);
				}
				if(k==2){
					f[i][j][2]=min(f[nowx][nowy][2]+sum[i][j]-a[i][j-1],f[i][j][2]);	
					f[i][j][2]=min(f[nowx][nowy][1]+sum[i][j]-a[i][j-1]-a[i-1][j],f[i][j][2]);
				}
			}
		}
	}
	printf("%d\n",min(f[n][m][1],f[n][m][2]));
}

