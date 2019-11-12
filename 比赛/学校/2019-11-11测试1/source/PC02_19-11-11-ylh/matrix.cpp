#include <bits/stdc++.h>

int n,m,len[5005][5005],rank[5005],ans=0;
char G[5005][5005];
std::stack<int>vis[5005];

void radix_sort(int j){
	for(int i=1;i<=n;++i)vis[len[i][j]].push(i);
	int tl=0;
	for(int i=m;i>=0;--i)
		while (!vis[i].empty()){rank[++tl]=vis[i].top();vis[i].pop();}
}

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",G[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if (G[i][j]=='1')len[i][j]=len[i][j-1]+1;
	for(int i=1;i<=n;++i)rank[i]=i;
	for(int j=1;j<=m;++j){
		radix_sort(j);
	//	for(int i=1;i<=n;++i)printf("%d ",rank[i]);printf("\n");
		for(int i=1;i<=n;++i)ans=std::max(ans,i*len[rank[i]][j]);
	}printf("%d",ans);
	return 0;
}
