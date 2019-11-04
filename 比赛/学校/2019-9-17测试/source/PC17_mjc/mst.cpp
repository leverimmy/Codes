#include<bits/stdc++.h>
using namespace std;
int ans[50];
int vis[50];
struct node{
	int a;
	int b;
	int u;
	int v;
}in[100];
double mjc=0x3f3f3f3f;
int kk[100];
int n,m;
void dfs(int step){
	if(step==n){
		double ans1=0;
		double ans2=0;
		memset(kk,0,sizeof(kk));
		for(int i=1;i<=n-1;i++){
			kk[in[ans[i]].u]=1;
			kk[in[ans[i]].v]=1;
		}
		for(int i=1;i<=n;i++){
			if(kk[i]==0){
				return;
			}
		}
		for(int i=1;i<=n-1;i++){
			ans1+=in[ans[i]].a;
		}
		for(int i=1;i<=n-1;i++){
			ans2+=in[ans[i]].b;
		}
		mjc=min(mjc,ans1/ans2);
		return;
	}
	for(int i=1;i<=m;i++){
		if(ans[step-1]<i){
			ans[step]=i;
			dfs(step+1);
			ans[step]=0;
		}	
	}
}
bool cmp(const node &x,const node &y){
	return x.a*y.b<x.b*y.a;
}
int fa[10010];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
double a1=0,a2=0;
void kruskal(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int eu=find(in[i].u);
		int ev=find(in[i].v);
		if(eu!=ev){
			fa[ev]=eu;
			cnt++;
			a1+=in[i].a;
			a2+=in[i].b;
			if(cnt==n-1){
				return;
			}
		}
	}
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&in[i].u,&in[i].v,&in[i].a,&in[i].b);
	}
	if(m<=20){
		dfs(1);
		printf("%.3lf",mjc);
	}	
	else{
		sort(in+1,in+1+m,cmp);
		kruskal();
		printf("%.3lf",a1/a2);
	}
}
