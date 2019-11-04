#include<bits/stdc++.h>
using namespace std;
const int N=200005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef long long ll;
int n,m;
vector<int> G[N];
int a[N],fa[N];
inline int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
int ans[N],siz[N];
int vis[N];
int main(){
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;a[i]=read();
	}
	for(int i=n;i>=1;i--){
		siz[a[i]]=1;vis[a[i]]=1;
		for(int j=0;j<G[a[i]].size();j++){
			int u=G[a[i]][j];
			if(!vis[u]) continue;
			int fx=findf(a[i]),fy=findf(u);
			if(fx==fy) continue;
			fa[fy]=fx;siz[fx]+=siz[fy];
		}
		if(siz[a[i]]<n-i+1) {
			ans[i]=0;
		}else ans[i]=1;
	}
	for(int i=1;i<=n;i++) puts(ans[i]?"YES":"NO");
	return 0;
}

/*
4 3 
1 2 
2 3 
3 4 
3
4
1
2
*/ 
