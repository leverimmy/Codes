#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define maxn 250000

struct Edge{
	int x,y,z;
	Edge(){}
	Edge(int xx,int yy,int zz) {
		x=xx,y=yy,z=zz;
	}
	bool operator < (const Edge& oth) const {
		return z<oth.z;
	}
};

int n,m,cc=0;
Edge e[maxn+5];

int getid(int x,int y) {
	return (x-1)*n+y;
}

void readin() {
	read(n),read(m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=2; k++) {
				char x;
				int y;
				while((~scanf("%c",&x))&&!isalpha(x));
				read(y);
				if(x=='X') continue;
				if(x=='D') e[++cc]=Edge(getid(i,j),getid(i+1,j),y);
				if(x=='R') e[++cc]=Edge(getid(i,j),getid(i,j+1),y);
			}
		}
	}
}

vector<int> tr[maxn+5];
int fa[maxn+5];

int find(int x) {
	if(fa[x]) return fa[x]=find(fa[x]);
	return x;
}

void kruskal() {
	int s=0;
	for(int i=cc;i>=1;i--) {
		if(s==n*m) return ;
		int fa1=find(e[i].x),fa2=find(e[i].y);
		if(fa1==fa2) continue;
		fa[fa1]=fa2;
		s++;
		tr[e[i].x].push_back(e[i].y);
		tr[e[i].y].push_back(e[i].x);
	}
	return ;
}

int d[maxn+5],anc[maxn+5][30];

void dfs(int x,int fa) {
	d[x]=d[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=0;i<tr[x].size();i++) {
		int y=tr[x][i];
		if(y==fa) continue;
		dfs(y,x);
	}
}

int findLCA(int x,int y) {
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--) {
		if(d[anc[x][i]]>=d[y]) x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--) {
		if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
	}
	return anc[x][0];
}

int main() {
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	readin();
	sort(e+1,e+cc+1);
	kruskal();
	dfs(1,0);
	
	int Q;
	read(Q);
	while(Q--) {
		int x1,y1,x2,y2;
		read(x1),read(y1),read(x2),read(y2);
		int x=getid(x1,y1),y=getid(x2,y2);
		int lca=findLCA(x,y);
		printf("%d\n",d[x]+d[y]-d[lca]*2);
	}
	
	return 0;
}
