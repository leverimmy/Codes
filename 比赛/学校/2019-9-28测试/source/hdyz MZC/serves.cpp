#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int read() {
	int w=1,x=0,ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar())if(ch=='-')w=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar())x=x*10+ch-'0';
	return x*w;
}
int n,m,Rc[30010];
namespace baoli {
	const int MAXN = 110;
	int f[MAXN][MAXN],ans = 0;
	void main() {
		memset(f,0x3f,sizeof(f));
		for(int i=1; i<=n; i++)f[i][i] = 0;
		for(int i=1; i<=m; i++) {
			int x = read(),y = read(),val = read();
			f[x][y] = f[y][x] = val;
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
		for(int i=1; i<=n; i++) {
			for(int pos=1; pos<=n; pos++) {
				bool flag = true;
				for(int k=1; k<=n; k++) {
					if(f[pos][k]<=f[pos][i]&&Rc[k]>Rc[i]) {
						flag = false;
						break;
					}
				}
				if(flag)ans++;
			}
		}
		printf("%d\n",ans);
	}
}
namespace pts40 {
	const int MAXN = (int)1e3+10;
	struct Edge {
		int from,to,val,nxt;
		Edge(int from,int to,int val,int nxt) {
			this->from = from;
			this->to = to;
			this->val = val;
			this->nxt = nxt;
		} Edge() {
		}
	} E[MAXN<<1];
	int head[MAXN],tot;
	inline void Add_Edge(int from,int to,int val){
		E[++tot] = Edge(from,to,val,head[from]),head[from] = tot;
	}
	struct Node {
		int dist,id;
		Node(int a,int b) {
			dist = a,id = b;
		}
		Node() {
		}
		bool operator <(const Node &x)const {
			return dist>x.dist;
		}
	};
	bool cmp(const Node &x,const Node &y){
		return x.dist<y.dist;
	}
	priority_queue<Node>q;
	int dist[MAXN][MAXN],vis[MAXN],maxx[MAXN][MAXN],p[MAXN][MAXN];
	Node li[MAXN][MAXN];
	void dj(int S) {
		memset(dist[S],0x3f,sizeof(dist[S]));
		memset(vis,0,sizeof(vis));
		dist[S][S] = 0;
		q.push(Node(0,S));
		while(!q.empty()) {
			Node x = q.top();
			q.pop();
			if(vis[x.id])continue;
			vis[x.id] = true;
			for(int i=head[x.id]; i; i=E[i].nxt) {
				int to = E[i].to;
				if(dist[S][to]>dist[S][x.id]+E[i].val) {
					dist[S][to] = dist[S][x.id] + E[i].val;
					q.push(Node(dist[S][to],to));
				}
			}
		}
		for(int i=1;i<=n;i++){
			li[S][i] = Node(dist[S][i],i);
		}
		sort(li[S]+1,li[S]+n+1,cmp);
		for(int i=1;i<=n;i++)p[S][i] = li[S][i].dist;
		maxx[S][0] = 0;
		for(int i=1;i<=n;i++){
			maxx[S][i] = max(maxx[S][i-1],Rc[li[S][i].id]);
		}
	}
	void main() {
		for(int i=1; i<=m; i++) {
			int x = read(),y = read(),val = read();
			Add_Edge(x,y,val),Add_Edge(y,x,val);
		}
		for(int i=1;i<=n;i++){
			dj(i);
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int v = dist[j][i];
				int loc = upper_bound(p[j]+1,p[j]+1+n,v)-p[j]-1;
				if(maxx[j][loc]<=Rc[i])ans++;
			}
		}
		printf("%d\n",ans);
	}
}
int main() {
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	n = read(),m = read();
	for(int i=1; i<=n; i++)Rc[i] = read();
	if(n<=100)baoli::main();
	if(n<=1000&&m<=1000)pts40::main();
	return 0;
}
