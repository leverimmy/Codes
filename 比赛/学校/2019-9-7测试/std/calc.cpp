#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int N = (int) 1e5;
using namespace std;

struct Edge  {
  int x, y, w;
  void init()  {
    scanf("%d %d %d", &x, &y, &w);
  }
};

Edge edge[N + 10];
int f[N + 10], size[N + 10];
int n;
long long ans;

bool cmpEdge(const Edge &a, const Edge &b)  {
  return a.w < b.w;
}
int father(int x)  {
  return f[x] == x ? x : f[x] = father(f[x]);
}
int main()  {
  freopen("calc.in", "r", stdin);
  freopen("calc.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i < n; ++i)  {
    edge[i].init();
  }
  sort(edge + 1, edge + n, cmpEdge);
  for (int i = 1; i <= n; ++i)  {
    f[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i < n; ++i)  {
    Edge *nt = edge + i;
    int fx = father(nt->x);
    int fy = father(nt->y);
    ans += (long long) size[fx] * size[fy] * nt->w;
    size[fx] += size[fy];
    f[fy] = fx;
  }
  cout << ans << endl;
}
