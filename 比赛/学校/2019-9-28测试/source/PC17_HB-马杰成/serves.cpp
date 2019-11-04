#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
const int maxm=2000010;
const int maxn=30010;
using namespace std;
int f[1010][1010];
int n,m;
int r[1010];
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
}now[maxn];
bool cmp (const pp &a,const pp &b){
	return a.d<b.d;
}
bool operator < (const pp &a,const pp &b){
	return a.d>b.d;
}
priority_queue<pp> pq;
vector<int > level[20];
void dij(int s){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	pq.push((pp){s,0});
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
int ans=0;
int main(){
	freopen("serves","r",stdin);
	freopen("serves","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=100){
		for(int i=1;i<=n;i++){
			scanf("%d",&r[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=inf;
			}
		}
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			f[x][y]=z;
			f[y][x]=z;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j || j==k || i==k) continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int flag=0;
				for(int k=1;k<=n;k++){
					if(f[i][k]<=f[i][j]){
						if(r[k]>r[j]){
							flag=1;
							break;
						}
					}
				}
				if(!flag){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&r[i]);
		}
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}	
		for(int i=1;i<=n;i++){
			dij(i);
			int maxx=0;
			memset(now,0,sizeof(now));
			for(int j=1;j<=n;j++){
				now[j].d=dis[j];
				now[j].ind=j;
			}
			sort(now+1,now+n+1,cmp);
			for(int j=1;j<=n;j++){
				maxx=max(maxx,r[now[j].ind]);
				if(maxx<=r[now[j].ind]){
					ans++;
				}
			}
		} 
		printf("%d\n",ans);
	}
} 
