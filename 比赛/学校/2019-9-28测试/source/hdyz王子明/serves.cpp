#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn = 30005;
const int maxm = 150005;
const int INF = 0x3f3f3f3f;

struct Edge{
	int x, y, w, nxt;
}e[maxm << 1 | 1];

struct Node{
	int u, val;
	bool operator < (const Node &rhs) const {
		return val > rhs.val;
	}
};

int n, m, cnt;
int fr, to, haj;

int head[maxn], val[maxn];

int dis[1005][1005];

long long ans;

bool vis[maxn];

int read(void)
{
	int s = 0, w = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
	for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

inline void add(int x, int y, int w)
{
	e[++cnt].x = x;
	e[cnt].y = y;
	e[cnt].w = w;
	e[cnt].nxt = head[x];
	head[x] = cnt;
}

void Dijkstra(int S)
{
	priority_queue<Node> Q;
	while(!Q.empty()) Q.pop();
	memset(vis, false, sizeof(vis));
	dis[S][S] = 0;
	Q.push((Node){S, 0});
	while(!Q.empty())
	{
		int x = Q.top().u;
		Q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = head[x]; i != -1; i = e[i].nxt)
		{
			int y = e[i].y;
			if(vis[y]) continue;
			if(dis[S][y] > dis[S][x] + e[i].w) 
			{
				dis[S][y] = dis[S][x] + e[i].w;
				Q.push((Node){y, dis[S][y]});
			}
		}
	}
}

int main()
{
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	memset(head, -1, sizeof(head));
	n = read(); m = read();
	if(n <= 100)
	{
		for(int i = 1; i <= n; i++) val[i] = read();
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1; i <= n; i++) dis[i][i] = 0;
		for(int i = 1; i <= m; i++)
		{
			fr = read(); to = read(); haj = read();
			dis[fr][to] = dis[to][fr] = min(dis[fr][to], haj);
		}
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)	
				for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++) 
			{
				if(i == j) continue;
				bool flag = true;
				for(int k = 1; k <= n; k++) 
				{
					if(k == i || k == j) continue;
					if(dis[i][j] < dis[i][k]) continue;
					if(val[k] > val[i]) 
					{
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		cout << ans << '\n';
	}
	else if(n <= 1000) 
	{
		for(int i = 1; i <= n; i++) val[i] = read();
		for(int i = 1; i <= m; i++)
		{
			fr = read(); to = read(); haj = read();
			add(fr, to, haj);
			add(to, fr, haj);
		}
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1; i <= n; i++) Dijkstra(i);
		for(int i = 1; i <= n; i++) 
		{
			for(int j = 1; j <= n; j++) 
			{
				if(i == j) continue;
				bool flag = true;
				for(int k = 1; k <= n; k++)
				{
					if(i == k || j == k) continue;
					if(dis[i][j] < dis[k][i]) continue;
					if(val[k] > val[i]) 
					{
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
