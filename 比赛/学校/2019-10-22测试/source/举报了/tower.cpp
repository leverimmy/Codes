#include <bits/stdc++.h>
#define maxn 1005
#define maxm 1000005
int n,x[maxn],y[maxn],u[maxm],v[maxm],w[maxm],rank[maxm],ans,tl=0;
int cmp(int a,int b){return w[a]<w[b];}
int dis(int a,int b){return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);}
namespace dsu {
	int fa[maxn]={0};
	int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
}

int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			{u[++tl]=i;v[tl]=j;w[tl]=dis(i,j);rank[tl]=tl;}
	std::sort(rank+1,rank+tl+1,cmp);
	for(int j=1;j<=tl;++j){
		int i=rank[j];
		int f1=dsu::getf(u[i]),f2=dsu::getf(v[i]);
		if (f1==f2)continue;
		ans=w[i];
		dsu::fa[f1]=f2;
	}printf("%d",ans);
	return 0;
}
