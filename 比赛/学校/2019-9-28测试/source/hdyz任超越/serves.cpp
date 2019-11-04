#include <iostream>
#include <cstdio>
#include <algorithm>
#define Re register
using namespace std;

const int maxn = 30010;

int n, m, x, y, z;
int cnt, fx, fy, tot, lca, lgg, d, flag, ans;
int r[maxn], f[maxn];
int head[maxn], fa[maxn][25], depth[maxn], dis[1010][1010], val[maxn];

struct Edge{
	int u, v, w, next;
}e[maxn*10];

struct node{
	int u, v, w;
	friend bool operator < (node x, node y){
		return x.w < y.w;
	}
}a[maxn*10];

int f_;
char ch_;
template <class T>
	inline T read(T &x_){
		x_ = 0, f_ = 1, ch_ = getchar();
		while (ch_ < '0' || ch_ > '9'){if (ch_ == '-') f_ = -1; ch_ = getchar();}
		while (ch_ >= '0' && ch_ <= '9') x_ = (x_ << 3) + (x_ << 1) + ch_ - 48, ch_ = getchar();
		return x_ *= f_;
	}
	
int get(int x){
	if (x == f[x]) return x;
	return f[x] = get(f[x]);
}

void add (int u, int v, int w){
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
	return;
}

void Kurskal(){
	for (Re int i = 1;i <= n; ++i) f[i] = i;
	for (Re int i = 1;i <= m; ++i){
		fx = get(a[i].u);
		fy = get(a[i].v);
		if (fx == fy) continue;
		tot++;
		f[fx] = fy;
		add (a[i].v, a[i].u, a[i].w);
		add (a[i].u, a[i].v, a[i].w);
		if (tot == n-1) break;
	}
}

void dfss (int u, int F){
	for (Re int i = head[u]; i ;i = e[i].next){
		if (e[i].v == F) continue;
		val[e[i].v] += e[i].w;
		val[e[i].v] += val[u];
		dfss (e[i].v, u);
	}
}

void dfs (int u, int F){
	fa[u][0] = F;
	depth[u] = depth[F] + 1;
	for (Re int i = 1; (1 << i) <= depth[u]; ++i){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for (Re int i = head[u]; i ;i = e[i].next){
		if (e[i].v == F) continue;
		dfs (e[i].v, u);
	}
}

int Lca (int x, int y){
	if (depth[x] > depth[y]) swap(x, y);
	for (Re int i = lgg; i >= 0; --i){
		if (depth[y] - (1 << i) >= depth[x]) 
			y = fa[y][i];
	}
	if (x == y) return x;
	for (Re int i = lgg; i >= 0; --i){
		if (fa[x][i] != fa[y][i])
			x = fa[x][i];
			y = fa[y][i];
	}
	return fa[x][0];
}

int main(){
	freopen ("serves.in", "r", stdin);
	freopen ("serves.out", "w", stdout);
	read(n);
	read(m);
	for (Re int i = 1;i <= n; ++i) read(r[i]);
	for (Re int i = 1;i <= m; ++i){
		read(a[i].u);
		read(a[i].v);
		read(a[i].w);
	}
	sort (a + 1, a + m + 1);
	Kurskal();
	while ((1 << lgg) <= n) lgg++;
	dfss (1, 1);
	dfs (1, 1);
	for (Re int i = 1;i <= n; ++i)
		for (Re int j = i + 1;j <= n; ++j){
			dis[i][j] = dis[j][i] = val[i] + val[j] - 2 * val[Lca(i, j)];
//			printf("%d %d %d\n",i, j, dis[i][j]);
		}
	for (Re int i = 1;i <= n; ++i){//b
		for (Re int j = 1;j <= n; ++j){//a
			d = dis[i][j];
			flag = 0;
			for (Re int k = 1;k <= n; ++k){// c
				if (dis[j][k] > d || k == i) continue;
				if (r[k] > r[i]){
					flag = 1;
//					cout<<i <<" "<<j <<" "<<k<<endl;
					break;
				}
			}
			if (!flag) {
				ans++;
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
