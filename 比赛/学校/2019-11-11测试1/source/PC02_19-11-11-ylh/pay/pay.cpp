#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
struct segmentTree {
	int max[maxn<<2];
	void modify(int p,int l,int r,int v,int rt){
		if (l==r){max[rt]=v;return;}
		int mid=(l+r)>>1;
		if (p<=mid)modify(p,l,mid,v,rt<<1);
		else modify(p,mid+1,r,v,rt<<1|1);
		max[rt]=std::max(max[rt<<1],max[rt<<1|1]);
	}
}sgt;

const ll inf=(ll)1<<(ll)60;
ll ans=inf;
int val[maxn],max[maxn],ch[maxn][2],rev[maxn],fa[maxn],g[maxn],d[maxn],G,D,u[maxn],v[maxn],n,m,rank[maxn],cnt=0;
int gmax(int a,int b){if (val[a]<val[b])return b;return a;}
int not_root(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
void update(int x){max[x]=gmax(x,gmax(max[ch[x][0]],max[ch[x][1]]));}
void reverse(int x){rev[x]^=1;std::swap(ch[x][0],ch[x][1]);}
void pushdown(int x){if (rev[x]){reverse(ch[x][0]);reverse(ch[x][1]);}rev[x]=0;}
int cmp(int a,int b){return g[a]<g[b];}


void rotate(int x){
	int f=fa[x],g=fa[f],l=ch[f][1]==x;
	if (not_root(f))ch[g][ch[g][1]==f]=x;
	fa[x]=g;fa[f]=x;if(ch[x][l^1])fa[ch[x][l^1]]=f;
	ch[f][l]=ch[x][l^1];ch[x][l^1]=f;
	update(f);update(x);
}

void splay(int x){
	std::stack<int>stk;stk.push(x);
	int u=x;while (not_root(u))stk.push(u=fa[u]);
	while (!stk.empty()){pushdown(stk.top());stk.pop();}
	while (not_root(x))rotate(x);
}

void access(int x){
	for (int y=0;x;x=fa[y=x]){
		splay(x);ch[x][1]=y;update(x);
	}
}
int find_root(int x){
	access(x);splay(x);
	while (ch[x][0]) {pushdown(x);x=ch[x][0];}
	return x;
}
void make_root(int x){
	access(x);splay(x);reverse(x);
}
void split(int x,int y){
	make_root(y);access(x);splay(y);
}
void link(int u,int v){
	make_root(u);
	if (find_root(v)!=u) fa[u]=v;
}
void cut(int x,int y) {
    make_root(x);
    if (find_root(y)!=x||fa[x]!=y||ch[x][1]) return;
    fa[x]=ch[y][0]=0; return;
}
int is_connected(int x,int y){
	make_root(x);return find_root(y)==x;
}

void erase(int x){
//	printf("- %d - %d (%d %d)\n",u[x],v[x],g[x],d[x]);
	cnt--;
	cut(u[x],x+n);cut(x+n,v[x]);
	sgt.modify(x,1,m,0,1);
}

void add(int x){
	//printf("+ %d - %d (%d %d)\n",u[x],v[x],g[x],d[x]);
	cnt++;
	link(u[x],x+n);link(x+n,v[x]);sgt.modify(x,1,m,d[x],1);
}

void insert(int x){
//	printf("ins %d - %d (%d %d)\n",u[x],v[x],g[x],d[x]);
	if (!is_connected(u[x],v[x])){add(x);return;}
	split(u[x],v[x]);splay(u[x]);
//	printf("max = %d\n",max[u[x]]-n);
	if (val[max[u[x]]]<val[x+n])return;
	erase(max[u[x]]-n);add(x);
}

int main(){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&G,&D);
	for(int i=1;i<=m;++i){
		rank[i]=i;
		scanf("%d%d%d%d",&u[i],&v[i],&g[i],&d[i]);
		val[n+i]=d[i];
	}std::sort(rank+1,rank+m+1,cmp);
	for(int i=1;i<=m;++i){
		insert(rank[i]);
		if (cnt!=n-1)continue;
		//printf("max = %d\n",sgt.max[1]);
		ans=std::min(ans,(ll)g[rank[i]]*G+(ll)sgt.max[1]*D);
	}if (ans>=inf)printf("-1");
	else printf("%lld",ans);
}
	
	
	
	
	
