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
int f[N + 10];
int n, m;
int test;

bool cmpEdge(const Edge &a, const Edge &b)  {
  return a.w < b.w;
}
int father(int x)  {
  return f[x] == x ? x : f[x] = father(f[x]);
}
int main()  {
  freopen("unique.in", "r", stdin);
  freopen("unique.out", "w", stdout);

  scanf("%d", &test);
  while (test--)  {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)  {
      edge[i].init();
    }
    sort(edge + 1, edge + m + 1, cmpEdge);
    for (int i = 1; i <= n; ++i)  {
      f[i] = i;
    }
    bool result = true;
    for (int i = 1; i <= m; ++i)  {
      int j = i;
      int cnt = 0;
      while (j <= m  &&  edge[j].w == edge[i].w)
	++j;//找出所有权值与i号边相等的边 
      for (int k = i; k < j; ++k)  {
	Edge *nt = edge + k;
	int fx = father(nt->x);
	int fy = father(nt->y);
	if (fx != fy)  ++cnt;
      }
      for (int k = i; k < j; ++k)  {
	Edge *nt = edge + k;
	int fx = father(nt->x);
	int fy = father(nt->y);
	if (fx != fy)  f[fy] = fx, --cnt;
      }//判断权值相等的边是否形成了环 
      if (cnt != 0)  {
	result = false;
	break;
      }
      i = j - 1;
    }
    if (result == true)  printf("YES\n");
    else  printf("NO\n");
  }
}
