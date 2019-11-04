#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



struct edge{
    int u, v, w;
}e;
bool cmp(struct edge a, struct edge b) {
    return a.w>b.w;
}int m, n;
int ufs[60002];
struct edge Edges[200002];
vector <int> edges[60005];
vector <int> weight[60005];
int p[60005][15]; int depth[60005]; int depth2[60005];
 int vis[60005]={0};
void Union(int a, int b);
int getf(int a);
bool Find(int a, int b);
void dfs(int u, int f);
int LCA(int a, int b);
int kruskal_init();
int bfs_init();int r, c, t1, t2;
int hash(int x, int y) {return (x-1)*r+y;}
char s1[20], s2[20];


int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	kruskal_init(); depth2[1]=0; depth[0]=0;
	dfs(1, 0);
	int q; scanf("%d", &q);
	int a, b;
    while (q--) {
    	int t1, t2, t3, t4;
        scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
        a=hash(t1, t2); b=hash(t3, t4);
        int lca=LCA(a, b);
        //printf("%d %d %d\n", a, b, depth2[a]); 
        printf("%d\n", depth[a]-depth[lca]+depth[b]-depth[lca]);
    }
}

int kruskal_init() {
    
    scanf("%d %d", &r, &c);m=r*c; n=0;
	for (int i=1;i<=r;++i) {
		for (int j=1;j<=c;++j) {
			scanf("%s %d %s %d", &s1, &t1, &s2, &t2);
			if (s1[0]!='X') {
				++n;Edges[n-1].u=hash(i, j); Edges[n-1].v=hash(i+1, j); Edges[n-1].w=t1;
			}if (s2[0]!='X') {
				++n;Edges[n-1].u=hash(i, j); Edges[n-1].v=hash(i, j+1); Edges[n-1].w=t2;
			}
		}
	}
	for (int i = 1; i <= m; ++i) ufs[i]=i;
	 sort(Edges, Edges+n, cmp);
    int i = 0;//printf(">%d]\n", n);
    for (int j = 0; j < m; ++j) {
        while (i<n&&Find(Edges[i].u, Edges[i].v)) {
            //printf("%d %d %d %d\n", i, Edges[i].u, Edges[i].v, Edges[i].w);
            i++;
        }
        if (i>=n) break;
        edges[Edges[i].u].push_back(Edges[i].v);
        edges[Edges[i].v].push_back(Edges[i].u);
        weight[Edges[i].u].push_back(Edges[i].w);
        weight[Edges[i].v].push_back(Edges[i].w);
        Union(Edges[i].u, Edges[i].v);
       // printf(">%d %d %d %d\n", i, Edges[i].u, Edges[i].v, Edges[i].w);
    } return 0;
}

void dfs(int u, int f) {
	//printf("%d>", u);
    depth[u]=depth[f]+1;
    p[u][0]=f; 
    for (int i = 1; (1<<i)<=depth[u]; i++) {
        p[u][i]=p[p[u][i-1]][i-1];
    } int len=edges[u].size();
    //printf("!");
    for (int i = 0;i<len;++i) {
        if (edges[u][i]!=f) {
            depth2[edges[u][i]]=depth2[u]+weight[u][i];
            dfs(edges[u][i], u);
        }
    } return;
}int LCA(int a, int b) {
    if (vis[a]!=vis[b]) return -1;
    int ret = 2147483647;
    if (depth[a]>depth[b]) {
        swap(a, b);
    } for (int i = 14; i >=0; --i) {
        if (depth[a]<=depth[b]-(1<<i)) {
            //printf("1>%d %d\n",ret, val[b][i]);
            b=p[b][i]; 
        }
    } if (a==b) return a;
    for (int i = 14; i >= 0; i--) {
        if (p[b][i]==p[a][i]) continue;
        //printf("2>%d %d %d %d %d %d\n", ret, a, b, i, val[b][i], val[a][i]);
        a=p[a][i]; b=p[b][i]; 
    } return p[a][0];
}

int getf(int a) {
    int r;
    if (ufs[a]==a) return a;
    else {
        ufs[a]= getf(ufs[a]);
        return ufs[a];
    }
}
bool Find(int a, int b) {
    return getf(a)==getf(b);
}
void Union(int a, int b) {
    int f1 = getf(a); int f2=getf(b);
    if (f1>f2) ufs[f2]=f1;
    if (f2>f1) ufs[f1]=f2;
}
	


	

