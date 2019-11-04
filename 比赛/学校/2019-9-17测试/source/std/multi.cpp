#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int N = (int) 2e5;
using namespace std;

typedef int Arr32[N + 10];

Arr32 vis, nextNode, in, c, next, f, g;
double e[N + 10], dis[N + 10];
int n, m, ap;
int start, end;
int x, y, z;

void link(int x, int y, double weight)  {
  c[++ap] = y, next[ap] = g[x], g[x] = ap;  e[ap] = weight;
  c[++ap] = x, next[ap] = g[y], g[y] = ap;  e[ap] = weight;
}
void getRoute(int start, int end)  {
  int tail = start;
  dis[start] = 0;
  vis[start] = true;
  nextNode[start] = 0;
  in[start] = true;
  for (int z = tail; z; in[z] = false, z = nextNode[z])
      for (int x = g[z]; x; x = next[x])
	if (vis[c[x]] == false  ||  dis[c[x]] > dis[z] + e[x] + 1e-7)  {
	dis[c[x]] = dis[z] + e[x];
	vis[c[x]] = true;
	f[c[x]] = z;
	if (in[c[x]] == false)  {
	  in[c[x]] = true;
	  if (z != tail  &&  dis[nextNode[z]] > dis[c[x]])  {
	    nextNode[c[x]] = nextNode[z];
	    nextNode[z] = c[x];
	  }
	  else  {
	    nextNode[tail] = c[x];
	    nextNode[c[x]] = 0;
	    tail = c[x];
	  }
	}
      }
}
void printRoute(int node)  {
  if (node != start)
    printRoute(f[node]);
  printf("%d ", node);
}
int main()  {
  freopen("multi.in", "r", stdin);
  freopen("multi.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i)  {
    scanf("%d %d %d", &x, &y, &z);
    link(x, y, log(z));
  }
  cin >> start >> end;
  getRoute(start, end);
  printRoute(end);
}
