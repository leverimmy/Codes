#include<bits/stdc++.h>
#define inf 127
using namespace std;
const int maxn=200010;
const int maxm=300010;
struct node{
	int next;
	int to;
	double w;
}e[maxm];
double dis[maxn];
int head[maxn],cnt;
void add(int u,int v,double ww){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=ww;
	head[u]=cnt;
}
int n,m,s,t;
int inq[maxn];
int pre[maxn];
void spfa(int s){
	queue<int > q;
	q.push(s);
	memset(dis,inf,sizeof(dis));
	memset(inq,0,sizeof(inq));
	inq[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
//			qq oo;
//			oo.r2=dis[u].r2*e[i].w;
//			oo.r1=oo.r2/mod+dis[u].r1;
//			oo.r2%=mod;	
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				pre[v]=u;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

vector<int > p;
signed main(){
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;double w;
		scanf("%d%d%lf",&u,&v,&w);
		add(u,v,log2(w));
		add(v,u,log2(w));
	}
	scanf("%d%d",&s,&t);
	spfa(s);
	for(int i=t;i;i=pre[i]){
		p.push_back(i);
		if(i==s) break;
	}
	for(int i=p.size()-1;i>=0;i--){
		printf("%d ",p[i]);
	}
}
