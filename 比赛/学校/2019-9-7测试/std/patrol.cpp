#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define int64 long long
const int inf = (int) 1e9 + 10;
using namespace std;

typedef int Arr32[200010];

Arr32 c, next, g, e, dis1, dis2, from1, from2, nextNode, in;
int n, m, ap = 1;

void link(int x, int y, int a, int b)  {
  c[++ap] = y, next[ap] = g[x], g[x] = ap;  e[ap] = a;
  c[++ap] = x, next[ap] = g[y], g[y] = ap;  e[ap] = b;
}
bool update(int x, int dis, int from, int nowE)  {//更新最短路和次短路 
  if (from == nowE)  return false;
  if (dis1[x] > dis)  {
    if (from1[x] != from)
      dis2[x] = dis1[x], from2[x] = from1[x];
    dis1[x] = dis, from1[x] = from;
    return true;
  }
  else  if (dis2[x] > dis)
    if (from1[x] == from);
    else  {
      dis2[x] = dis, from2[x] = from;
      return true;
    }
  return false;//未更新 
}
int getRoute()  {
  int s = 1, tail = 0, head = 0;
  for (int i = 1; i <= n; ++i)
    dis1[i] = dis2[i] = inf;
  for (int x = g[s]; x; x = next[x])  {//从第一个结点出发访问它的邻接点 
    bool updated = update(c[x], e[x], x >> 1, -1);
    if (updated == true  &&  in[c[x]] == false)  { 
      if (tail == 0)  head = c[x];
      else  nextNode[tail] = c[x];
      tail = c[x];
      nextNode[c[x]] = 0;
      in[c[x]] = true;
    }
  } 
  for (int z = head; z; in[z] = false, z = nextNode[z])  {//从队头元素出发访问邻接点 
    if (dis1[z] >= dis1[s])  continue;
    for (int x = g[z]; x; x = next[x])  {
      bool updated = false;
      updated |= update(c[x], dis1[z] + e[x], from1[z], x >> 1);
      updated |= update(c[x], dis2[z] + e[x], from2[z], x >> 1);
      if (updated == true  &&  in[c[x]] == false)  {
	nextNode[tail] = c[x];
	tail = c[x];
	nextNode[c[x]] = 0;
	in[c[x]] = true;
      }
    }
  }
  if (dis1[s] >= inf)  return -1;
  return dis1[s];
}
int main()  {
  freopen("patrol.in", "r", stdin);
  freopen("patrol.out", "w", stdout);
  int x, y, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)  {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    link(x, y, a, b);
  }
  cout << getRoute() << endl;
}
