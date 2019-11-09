#include<bits/stdc++.h>
using namespace std;
int dep[50010],t1,t2,t3,edcnt,f[50010][18],n,k,head[50010],siz[50010];
long long ans;
struct edge{
	int to,nxt;
}ed[100010];
inline void addedge(int from,int to){
	ed[++edcnt].nxt=head[from];
	ed[edcnt].to=to;
	head[from]=edcnt;
}
namespace __10pts{
	void dfs(int now,int prev){
		dep[now]=dep[prev]+1;
		f[now][0]=prev;
		for(int i=1;i<=17;++i){
			f[now][i]=f[f[now][i-1]][i-1];
		}
		for(int i=head[now];i;i=ed[i].nxt){
			if(ed[i].to==prev)
				continue;
			dfs(ed[i].to,now);
		}
		return;
	}
	inline int lca(int x,int y){
		if(dep[x]<dep[y])
			swap(x,y);
		for(int i=17;i>=0;--i){
			if(dep[f[x][i]]>=dep[y])
				x=f[x][i];
		}
		if(x==y)
			return x;
		for(int i=17;i>=0;--i){
			if(f[x][i]!=f[y][i])
				x=f[x][i],y=f[y][i];
		}
		return f[x][0];
	}
	inline int dis(int x,int y){
		int z=lca(x,y);
		int qwq=abs(dep[z]-dep[x])+abs(dep[z]-dep[y]);
		return (qwq/k+(qwq%k!=0));
	//	return qwq;
	}
	void solve(){
		dfs(1,0);
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)
				ans+=dis(i,j);
		}
		cout<<ans;
	}
}
namespace __20pts{
	void dfs(int now,int prev){
		siz[now]++;
		for(int i=head[now];i;i=ed[i].nxt){
			if(ed[i].to==prev)
				continue;
			dfs(ed[i].to,now);
			siz[now]+=siz[ed[i].to];
		}
	}
	void solve(){
		dfs(1,0);
		for(int i=1;i<=n;++i){
			ans+=siz[i]*(n-siz[i]);
		}
		cout<<ans;
		return;
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&t1,&t2);
		addedge(t1,t2),addedge(t2,t1);
	}
	if(k==1){
		__20pts::solve();
		return 0;
	}
	__10pts::solve();
	return 0;
}
