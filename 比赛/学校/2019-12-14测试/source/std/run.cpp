#include<cstdio>
#include<algorithm>
#define maxn 120050
#define maxm 340050
using namespace std;
struct edge{
  int s,t,c;
}e[maxm];
int isp[maxn],tot;
int q[2*maxn],t[2*maxn],f[maxn],c[2*maxn];
int pr[22][maxn],mx[22][maxn],dist[maxn];
int f1,f2,n,m,x,y,Q,i,j;
bool cmpc(const edge &a,const edge &b)
{return a.c<b.c;}
int find(int x) 
{if(isp[x]!=x) isp[x]=find(isp[x]); return isp[x];}
void link(int x,int y,int z)
{q[++tot]=f[x]; f[x]=tot; t[tot]=y; c[tot]=z;}
void dfs(int x,int y,int z)
{
  pr[0][x]=y; mx[0][x]=z;
  dist[x]=dist[y]+1;
  for(int i=f[x];i;i=q[i])
    if (t[i]!=y)
      dfs(t[i],x,c[i]);
}
int query(int x,int y)
{
  int dt,i,fn=0;
  if (dist[x]<dist[y])
    dt=x,x=y,y=dt;
  dt=dist[x]-dist[y];
  for(i=0;dt;dt/=2,i++)
    if (dt&1){
      fn=max(fn,mx[i][x]);
      x=pr[i][x];
    }
  for(i=19;i>=0;i--)
    if (pr[i][x]!=pr[i][y])
    {
      fn=max(fn,mx[i][x]);
      fn=max(fn,mx[i][y]);
      x=pr[i][x];
      y=pr[i][y];
    }
  while (x!=y)
    {
      fn=max(max(fn,mx[0][x]),mx[0][y]);
      x=pr[0][x]; y=pr[0][y];
    }
  return fn;
}
int main()
{
  freopen("run.in","r",stdin);
  freopen("run.out","w",stdout);
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)
    scanf("%d %d %d",&e[i].s,&e[i].t,&e[i].c);
  sort(e+1,e+1+m,cmpc);
  for(i=1;i<=n;i++) isp[i]=i;
  for(i=1;i<=m;i++)
    {
      f1=find(e[i].s); f2=find(e[i].t);
      if (f1!=f2)
	link(e[i].s,e[i].t,e[i].c),link(e[i].t,e[i].s,e[i].c);
      isp[f1]=f2;
    }
  dfs(1,0,0);
  for(i=1;i<=19;i++)
    for(j=1;j<=n;j++)
      {
	x=pr[i-1][j];
	pr[i][j]=pr[i-1][x];
	mx[i][j]=max(mx[i-1][j],mx[i-1][x]);
      }
  scanf("%d",&Q);
  for(;Q--;)
    {
      scanf("%d %d",&x,&y);
      printf("%d\n",query(x,y));
    }
}
