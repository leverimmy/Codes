#include<bits/stdc++.h>
using namespace std;
int n,m,q,head[400010],edcnt,tmpval,tmppos,dis[200010];
bool vis[200010];
struct edge{
	int to,nxt,val;
}ed[400010];
struct status{
	int pos,dis;
	const bool operator < (const status &b)const{
		return dis>b.dis;
	}
};
inline void addedge(int from,int to,int val){
	ed[++edcnt].nxt=head[from],
	ed[edcnt].to=to,
	ed[edcnt].val=val,
	head[from]=edcnt;
}
inline int dij(){
	memset(dis,0x3f,sizeof(dis)),
	memset(vis,false,sizeof(vis));
	priority_queue<status>pq;
	dis[1]=0;
	pq.push((status){1,0});
	while(!pq.empty()){
		status now=pq.top();
		pq.pop();
		if(vis[now.pos])
			continue;
		vis[now.pos]=true;
		for(int i=head[now.pos];i;i=ed[i].nxt){
			if(dis[ed[i].to]>ed[i].val+dis[now.pos]){
				dis[ed[i].to]=ed[i].val+dis[now.pos];
				if(!vis[ed[i].to])	
					pq.push((status){ed[i].to,dis[ed[i].to]});
			}
		}
	}
	return dis[n];
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int t1,t2,t3;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&t1,&t2,&t3),
		addedge(t1,t2,t3),addedge(t2,t1,t3);
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&t1,&t2);
		tmpval=ed[(t1-1)*2+1].val,tmppos=(t1-1)*2+1;
		ed[tmppos].val=t2,ed[tmppos+1].val=t2;
		printf("%d\n",dij());
		ed[tmppos].val=tmpval,ed[tmppos+1].val=tmpval;
	}
	return 0;
}
