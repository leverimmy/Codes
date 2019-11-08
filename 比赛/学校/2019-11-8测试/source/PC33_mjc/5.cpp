#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int maxm=200010;
struct node{
	int u;
	int v;
	int w;
}e[maxm];
int fa[maxn];
int n,m;
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return fa[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int kruskal(){
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int eu=find(e[i].u);
		int ev=find(e[i].v);
		if(eu!=ev){
			cnt++;
			fa[ev]=eu;
			ans+=e[i].w;
			if(cnt==n-1){
				break;
			}
		}
	}
	return ans;
}

signed main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++)
			fa[i]=i;
		printf("%d\n",kruskal());
	}
}
