#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define maxn 400005
int n,m,t,vis[maxn]={0},u,v,l,r;
std::vector<std::pair<int,int> >rec[maxn<<2];

struct state {
	int x,y,ry;
};inline state newstate(int x,int y,int ry){state s;s.x=x;s.y=y;s.ry=ry;return s;}

namespace dsu {
	int fa[maxn]={0},rev[maxn]={0},dis[maxn]={0},rank[maxn]={0};
	std::stack<state>stk;
//	void reset(){std::memset(fa,0,sizeof(fa));std::memset(dis,0,sizeof(dis));}
	int getf(int x){
		if (!fa[x]){dis[x]=0;return x;}
		int f=getf(fa[x]);
		dis[x]=dis[fa[x]]^rev[x];
		return f;
	} int merge(int x,int y){
		int f1=getf(x),f2=getf(y);
		if (f1!=f2){
			if (rank[f1]<rank[f2]){std::swap(f1,f2);std::swap(x,y);}
			stk.push(newstate(f2,f1,rank[f1]));
			fa[f2]=f1;rev[f2]=dis[x]^dis[y]^1;
			if (rank[f1]==rank[f2])rank[f1]++;
			return 2;
		}else {
			if (dis[x]==dis[y])return 0;
			return 1;
		}
	}inline void cancel(){
		state s=stk.top();stk.pop();
		fa[s.x]=0;rev[s.x]=0;dis[s.x]=0;rank[s.y]=s.ry;
	}
}

void add_edge(int l,int r,int L,int R,int x,int y,int rt){
	if (l>R||r<L)return;
	if (l<=L&&R<=r){rec[rt].push_back(std::make_pair(x,y));return;}
	add_edge(l,r,L,(L+R)>>1,x,y,rt<<1);
	add_edge(l,r,((L+R)>>1)+1,R,x,y,rt<<1|1);
}

void dfs(int l,int r,int rt,int flag){
	int cnt=0;
	if (flag)
	for(register int i=0;i<rec[rt].size();++i){
		std::pair<int,int>pii=rec[rt][i];
		int d=dsu::merge(pii.first,pii.second);
		if (d==2)cnt++;
		if (!d){flag=0;break;}
	} if (l==r){vis[l]=flag;for(int i=1;i<=cnt;++i)dsu::cancel();return;}
	dfs(l,(l+r)>>1,rt<<1,flag);
	dfs(((l+r)>>1)+1,r,rt<<1|1,flag);
	for(int i=1;i<=cnt;++i)dsu::cancel();
}

inline int read(){
	char c=getchar();int x=0;
	while (c>'9'||c<'0')c=getchar();
	while ('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x;
}

int main(){
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;++i){
		u=read();v=read();l=read();r=read();
		add_edge(l+1,r,1,t,u,v,1);
	}dfs(1,t,1,1);
	//assert(dsu::stk.empty());
	for(int i=1;i<=t;++i){if (vis[i])puts("Yes");else puts("No");}
	return 0;
}






