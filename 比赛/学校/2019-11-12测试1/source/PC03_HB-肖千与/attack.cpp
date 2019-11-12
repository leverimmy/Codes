#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
typedef long long ll;
vector<int> G[N];
int n;
ll a[N],dep[N],mx_dep[N],kon[N];
struct node{
	ll x,y;
	node(int a=0,int b=0){x=a,y=b;}
};
inline node max(const node &a,const node &b){
	node c;
	if(a.x==b.x) {
		return node(a.x,b.x);
	}
	int t=max(a.x,b.x);
	if(a.x==t) return node(t,max(a.y,b.x));
	else return node(t,max(a.x,b.y));
}
inline node max(const node &a,int b){
	if(b>a.x) {
		return node(b,a.x);
	}else if(b>a.y) return node(a.x,b);
	else return node(a.x,a.y);
}
vector<node> pre[N];
ll res=0,ans=0;
void dfs(int u,int f){
	pre[u].resize(G[u].size()+1);
	mx_dep[u]=a[u];
	ll mx1=0,mx2=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		pre[u][i+1]=pre[u][i];
		if(v==f) continue;
		dfs(v,u);
		if(mx_dep[v]>mx1) {
			mx2=mx1;
			mx1=mx_dep[v];
		}else if(mx_dep[v]>mx2) {
			mx2=mx_dep[v];
		}
		mx_dep[u]=max(mx_dep[u],mx_dep[v]+a[u]);
		pre[u][i+1]=max(pre[u][i],mx_dep[v]);
	}
	kon[u]=max(mx_dep[u],mx1+mx2+a[u]);
}
void dfs(int u,int f,ll w1,ll w2){
	ans=max(ans,max(w1,w2)+kon[u]);
	node suf;
	for(int i=G[u].size()-1;i>=0;i--){
		int v=G[u][i];
		if(v==f) continue;
		node t=max(suf,pre[u][i]);
		dfs(v,u,max(t.x+a[u],w1),max(t.x+t.y+a[u],w2));
		suf=max(suf,mx_dep[v]);
	}
}
int main(){
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++) {
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
} 
