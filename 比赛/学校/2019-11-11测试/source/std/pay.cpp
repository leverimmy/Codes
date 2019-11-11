#include <iostream>   //2011
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define int64 long long

using namespace std;
struct Node{
    int x,y,v1,v2;
}a[100100];
int n,m,Au,Ag,MAg,whe,tot;
int head[1010],next[100100],to[100100],top = 1,val[100100],fnt[100100],who[100100];
int64 ans = ((int64) 1 << 62);
bool vis[110];

bool cmp(Node x,Node y)   {   return x.v1 < y.v1 || (x.v1 == y.v1 && x.v2 < y.v2);  }
void link(int x,int y,int v)
{
    fnt[head[x]] = ++top;  next[top] = head[x];  head[x] = top;
    to[top] = y;   val[top] = v;   who[top] = x;
}
void find(int x1,int fa,int x2,int MaxAg,int whe2)
{
    if (x1 == x2)   {MAg = MaxAg;whe = whe2;return ;}
    if (MAg)  return ;
    for (int i = head[x1],y;y = to[i],i;i = next[i])
        if (y != fa)  {
            int v = MaxAg,whe3 = whe2;
            if (val[i] > v)   v = val[i],whe3 = i;
            find(y,x1,x2,v,whe3);
        }
}
void dfs(int node,int fa)
{
    tot++;
    for (int i = head[node],y;y = to[i],i;i = next[i])
        if (y != fa)   MAg = max(val[i],MAg),dfs(y,node);
}
void work()
{
    sort(a + 1,a + m + 1,cmp);
    for (int i = 1;i <= m;i++)
        {
            int z = i;  while (a[z].v1 == a[i].v1)  z++;   z--;
            for (int j = i;j <= z;j++)   {
                if (a[j].x == a[j].y)   continue ;
                MAg = 0;whe = 0;    find(a[j].x,0,a[j].y,0,0);
                if (!MAg || MAg > a[j].v2)  {
                    link(a[j].x,a[j].y,a[j].v2);  link(a[j].y,a[j].x,a[j].v2);
                    if (whe)  {
                        fnt[next[whe]] = fnt[whe];   next[fnt[whe]] = next[whe];
                        fnt[next[whe^1]] = fnt[whe^1];   next[fnt[whe^1]] = next[whe^1];
                        if (whe == head[who[whe]])    head[who[whe]] = next[whe];
                        if ((whe^1) == head[who[whe^1]])    head[who[whe^1]] = next[whe^1];
                    }
                }
            }
            tot = 0;MAg = 0;
            dfs(1,0);   if (tot == n)   ans = min(ans,(int64)a[i].v1 * Au + (int64)MAg * Ag);
            i = z;
        }
    if (ans == ((int64) 1 << 62))   printf("-1");
    else 
        cout << ans;
}

int main()
{
	freopen("pay.in","r",stdin);     freopen("pay.out","w",stdout);
    cin >> n >> m >> Au >> Ag;
    for (int i = 1;i <= m;i++)
        scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i].v1,&a[i].v2);
    work();
}
