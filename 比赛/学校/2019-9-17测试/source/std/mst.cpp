#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int N = (int) 1e5;
using namespace std;

struct Edge  {
  int x, y, a, b;
  double w;
  void init()  {
    scanf("%d %d %d %d", &x, &y, &a, &b);
  }
};

Edge edge[N + 10];
int f[N + 10];
int n, m;
int test;

bool cmpEdge(const Edge &a, const Edge &b)  {
  return a.w < b.w;
}
int father(int x)  {
  return f[x] == x ? x : f[x] = father(f[x]);
}
bool judge(double &ans)  {
  for (int i = 1; i <= m; ++i)  {
    Edge *nt = edge + i;
    nt->w = nt->a - ans * nt->b;
  }
  sort(edge + 1, edge + m + 1, cmpEdge);
  for (int i = 1; i <= n; ++i)
    f[i] = i;
  long long totA = 0, totB = 0;
  for (int i = 1; i <= m; ++i)  {
    Edge *nt = edge + i;
    int fx = father(nt->x);
    int fy = father(nt->y);
    if (fx == fy)  continue;
    totA += nt->a;
    totB += nt->b;
    f[fy] = fx;
  }
  if ((double) totA / totB < ans - 1e-8)  {
    ans = (double) totA / totB;
    return true;
  }
  return false;
}
int main()  {
  freopen("mst.in", "r", stdin);
  freopen("mst.out", "w", stdout);

  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)  {
    edge[i].init();
  }
  double ans = 1e9;
  while (judge(ans) == true);
  printf("%.10lf\n", ans);
}
