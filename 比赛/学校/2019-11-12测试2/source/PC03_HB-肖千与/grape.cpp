#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=400005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n,m,T;
struct edge{
	int x,y;
	edge(int a=0,int b=0){x=a,y=b;}
};
struct Rev{
	edge p;int type;
	Rev(){}
	Rev(edge a,int tp){p=a,type=tp;}
};
vector<Rev> rev[N<<2];
vector<edge> e[N<<2];
int ans[N],fa[N],v[N],rnk[N];
inline int findf(int &x){int c=0;while(x!=fa[x]) c^=v[x],x=fa[x];return c;}
#define ls rt<<1
#define rs rt<<1|1
inline void modify(int rt,int l,int r,int L,int R,int x,int y){
	if(L<=l&&r<=R) {
		e[rt].push_back(edge(x,y));
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) modify(ls,l,mid,L,R,x,y);
	if(R>mid) modify(rs,mid+1,r,L,R,x,y);
}
inline void query(int rt,int l,int r){
	int flag=0,cnt=0;
	if(e[rt].size()) {
		for(int i=0;i<e[rt].size();i++){
			int x=e[rt][i].x,y=e[rt][i].y;
			int v1=findf(x),v2=findf(y);
			if(x==y) {
				if(v1==v2){
					for(int j=l;j<=r;j++) ans[j]=0;
					flag=1;break;
				}else continue;
			}
			if(rnk[x]<rnk[y]) swap(x,y);
			fa[y]=x;v[y]=v1^v2^1;int tp=0;
			if(rnk[x]==rnk[y]) ++rnk[x],tp=1;
			rev[rt].push_back(Rev(edge(x,y),tp));
		}
	}
	int mid=(l+r)>>1;
	if(!(flag||l==r)) query(ls,l,mid),query(rs,mid+1,r);
	for(int i=rev[rt].size()-1;i>=0;i--) {
		int x=rev[rt][i].p.x,y=rev[rt][i].p.y;
		fa[y]=y,v[y]=0;
		if(rev[rt][i].type) rnk[x]--;
	}
}
int main(){
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),l=read()+1,r=read();
		if(l>r) continue;
		modify(1,1,T,l,r,u,v);
	}  
	for(int i=1;i<=T;i++) fa[i]=i,rnk[i]=1,ans[i]=1;
	query(1,1,T);
	for(int i=1;i<=T;i++) {
		puts(ans[i]?"Yes":"No");
	}
	return 0;
} 
