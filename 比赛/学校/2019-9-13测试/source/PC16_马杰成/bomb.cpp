#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
const int maxm=200010;
const int maxn=5010;
struct node{
	int next;
	int to;
}e[maxm],qq[maxm];
int cnt,cnt2,head[maxn],head2[maxn];
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
} 
void ad(int u,int v){
	qq[++cnt2].next=head2[u];
	qq[cnt2].to=v; 
	head2[u]=cnt2;
} 
int w[505][505];
int vis[maxn];
int n,m;
vector<int >pro[maxn]; 
int pre[maxn];
int dis[maxn];
int inq[maxn];
void spfa(){
	queue<int> q;
	memset(dis,inf,sizeof(dis));
	memset(inq,0,sizeof(inq));
	q.push(1);
	inq[1]=1;
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+w[u][v]){
				dis[v]=dis[u]+w[u][v];
				pre[v]=u;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int ans=0;
vector<int > bk;
signed main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y);
		add(y,x);
	}
	for(int i=2;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x;
			scanf("%d",&x);
			pro[x].push_back(i);	
		}
	}
//	queue<int > q;
//	q.push(n);
//	while(!q.empty()){
//		int u=q.front();
//		q.pop();
//		for(int i=head2[u];i;i=qq[i].next){
//			int v=qq[i].to;
//			du[v]--;
//			if(!du[v]){
//				q.push(v);
//				vis[v]=1;
//			}
//		}
//	}
//	if(!vis[1]){
//		printf("Mission Failed\n");
//	}
	
	spfa();
	ans+=dis[n];
	for(int i=n;i;i=pre[i]){
		w[i][pre[i]]=0;
		w[pre[i]][i]=0;
		if(i==1) break;
	}
		printf("Mission Failed\n");
}
