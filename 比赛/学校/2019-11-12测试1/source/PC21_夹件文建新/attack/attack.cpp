#include<bits/stdc++.h>
using namespace std;
int ans,t1,t2,n,head[100010],len1[100010],len2[100010],edcnt,val[100010],pre1[100010],pre2[100010];
bool flag[100010],vis[100010];
struct edge{
	int to,nxt;
}ed[100010];
inline void addedge(int from,int to){
	ed[++edcnt].nxt=head[from],
	head[from]=edcnt,
	ed[edcnt].to=to;
}
int dfs(int now,int prev,int len){
//	printf("%d\n",now);
	vis[now]=true;
	for(int i=head[now];i;i=ed[i].nxt){
		if(ed[i].to==prev||flag[ed[i].to])
			continue;
		int tmp=dfs(ed[i].to,now,len+val[ed[i].to]);
		if(tmp>=len1[now])
			len2[now]=len1[now],len1[now]=tmp,pre2[now]=pre1[now],pre1[now]=ed[i].to;
		else if(tmp<len1[now]&&tmp>=len2[now])
			len2[now]=tmp,pre2[now]=ed[i].to;
	}
	return len1[now]+val[now];
}
void dlt(int tgt){
//	printf("%d\n",tgt);
	if(!tgt)
		return;
	flag[tgt]=true;
	dlt(pre1[tgt]);
}
int main(){
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&val[i]);
	for(int i=1;i<n;++i)
		scanf("%d%d",&t1,&t2),addedge(t1,t2),addedge(t2,t1);
	dfs(1,0,0);
//	printf("\n\n\n");
//	for(int i=1;i<=n;++i)
//		printf("%d %d\n",len1[i],len2[i]);
	int tmp=0,tmppos=0;
	for(int i=1;i<=n;++i){
		if(len1[i]+len2[i]+val[i]>tmp)
			tmp=len1[i]+len2[i]+val[i],tmppos=i;
	}
	dlt(pre1[tmppos]),dlt(pre2[tmppos]),flag[tmppos]=true,ans+=tmp;
	memset(pre1,0,sizeof(pre1)),memset(pre2,0,sizeof(pre2)),
	memset(len1,0,sizeof(len1)),memset(len2,0,sizeof(len2));
	memset(vis,false,sizeof(vis));
//	printf("\n\n\n");
//	printf("ans:%d",ans);
//	printf("\n\n\n");
	for(int i=1;i<=n;++i){
		if(vis[i]||flag[i])
			continue;
		dfs(i,0,0);
	}
	tmp=0,tmppos=0;
	
//	for(int i=1;i<=n;++i)
//		printf("%d %d\n",len1[i],len2[i]);
	for(int i=1;i<=n;++i){
		if(flag[i])
			continue;
		if(len1[i]+len2[i]+val[i]>tmp)
			tmp=len1[i]+len2[i]+val[i],tmppos=i;
	}
	ans+=tmp;
	printf("%d",ans);
	return 0;
}
