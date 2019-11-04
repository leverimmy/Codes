#include <queue>
#include <cstdio>
#include <cstring>
#define re register
int v, c;
template <class T> T read(T& x) {
	x = 0; v = 1; c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') v = -1;;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x *= v;
}
template <class T> inline T min(T x, T y) {return x < y ? x : y;}
const int N = 60010, M = 310;
int n, m, cnt, x, y, w, val[N], head[N], d[M][M], sum[N], ans, dis[N];
bool flag, vis[N];
struct Edge {int y, w, nxt;} e[N];
inline void add(int x, int y, int w) {
	e[++cnt].y = y; e[cnt].w = w; e[cnt].nxt = head[x]; head[x] = cnt;
}
std::queue <int> q;
void spfa(int s) {
	memset(dis, 63, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[s] = 1; dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		vis[x] = 0;
		for (re int i = head[x]; i; i = e[i].nxt) {
			int y = e[i].y;
			if (dis[y] > dis[x] + e[i].w) {
				dis[y] = dis[x] + e[i].w;
				if (!vis[y]) {
					vis[y] = 1; q.push(y);
				}
			}
		}
	}
}
void floyed() {
	memset(d, 63, sizeof(d));
	for (re int i = 1; i <= m; ++i) {
		read(x); read(y); read(w);
		d[x][y] = d[y][x] = w;
	}
	for (re int k = 1; k <= n; ++k) {
		for (re int i = 1; i <= n; ++i) {
			d[i][i] = 0;
			for (re int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (re int a = 1; a <= n; ++a) {
		flag = 0;
		for (re int b = 1; b <= n; ++b) {
			if (a == b) continue;
			for (re int c = 1; c <= n; ++c) {
				if (a == c) continue;
				if (d[a][c] <= d[a][b] && val[c] > val[b]) {
					flag = 1; break;
				}
			}
			if (!flag) ++ans;
		}
	}
	printf("%d", ans);
}
int main() {
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	read(n); read(m);
	for (re int i = 1; i <= n; ++i) {
		read(val[i]);
	}
	if (n <= 300) {
		floyed(); return 0;
	}
	for (re int i = 1; i <= m; ++i) {
		read(x); read(y); read(w);
		add(x, y, w); add(y, x, w);
	}
	for (re int a = 1; a <= n; ++a) {
		spfa(a); flag = 0;
		for (re int b = 1; b <= n; ++b) {
			if (a == b) continue;
			for (re int c = 1; c <= n; ++c) {
				if (a == c) continue;
				if (dis[c] <= dis[b] && val[c] > val[b]) {
					flag = 1; break;
				}
			}
			if (!flag) ++ans;
		}
	}
	printf("%d ", ans);
	return 0;
}
