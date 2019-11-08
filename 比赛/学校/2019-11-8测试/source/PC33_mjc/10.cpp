#include<bits/stdc++.h>
using namespace std;
const int maxm=1000010;
const int maxn=100100;
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}  
int dfn[maxn],low[maxn],ind,top,s[maxn],cntg,siz[maxn],instack[maxn],group[maxn];
void tarjan(int u){
	dfn[u]=low[u]=++ind;
	s[++top]=u;
	instack[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(dfn[v]){
			if(instack[v]){
				low[u]=min(low[u],dfn[v]);
			}
		}
		else{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u]){
		int v;
		siz[++cntg]=0;
		do{
			v=s[top--];
			instack[v]=0;
			siz[cntg]++;
			group[v]=cntg;
		}while(v!=u);
	}
}
int n,m;
void clear(){
	cntg=0;
	ind=0;
	top=0;
	cnt=0;
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));	
	memset(siz,0,sizeof(siz));
	memset(group,0,sizeof(group));
	memset(s,0,sizeof(s));
}
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		clear();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		printf("%d\n",cntg);
	}
}
