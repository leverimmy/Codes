#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int inf = (int) 1e9 + 10;
using namespace std;

typedef int Arr32[20010];

Arr32 c, next, g, e, dis, vis, q, s, t;
int n, m, mark, id, ap = 1;
int S, T;

void link(int &x, int &y, int cap)  {
  if (x == 0)  x = ++id;
  if (y == 0)  y = ++id;
  c[++ap] = y, next[ap] = g[x], g[x] = ap;  e[ap] = cap;
  c[++ap] = x, next[ap] = g[y], g[y] = ap;  e[ap] = 0;
}
bool bfs(int s, int t)  {
  int tail = 1;
  dis[s] = 0;
  vis[s] = ++mark;
  q[tail] = s;
  for (int i = 1; i <= tail; ++i)  {
    int z = q[i];
    for (int x = g[z]; x; x = next[x])
      if (vis[c[x]] < mark  &&  e[x ^ 1] > 0)  {
	vis[c[x]] = mark;
	dis[c[x]] = dis[z] + 1;
	q[++tail] = c[x];
	if (c[x] == t)  return true;
      }
  }
  return false;
}
int dfs(int z, int end, int rest)  {
  if (end == z  ||  rest == 0)  return rest;
  int flow = 0, fl;
  for (int x = g[z]; x; x = next[x])
    if (e[x] > 0  &&  vis[c[x]] == mark)
      if (dis[c[x]] == dis[z] - 1)  {
	fl = dfs(c[x], end, rest < e[x] ? rest : e[x]);
	if (fl == 0)  continue;
	flow += fl, rest -= fl;
	e[x] -= fl, e[x ^ 1] += fl;
	if (rest == 0)  return flow;
      }
  dis[z] = inf;
  return flow;
}
int main()  {
  freopen("flow.in", "r", stdin);
  freopen("flow.out", "w", stdout);
  int x, y, c;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)  {
    scanf("%d", &c);
    link(s[i], t[i], c);
  }
  for (int i = 1; i <= m; ++i)  {
    scanf("%d %d %d", &x, &y, &c);
    link(t[x], s[y], c);
  }
  scanf("%d %d", &S, &T);
  S = s[S];
  T = t[T];
  int flow = 0;
  while (bfs(T, S))  flow += dfs(S, T, inf);
  cout << flow << endl;
}
