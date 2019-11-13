#include<cstdio>
#include<algorithm>
#define ll long long
#define maxo 1e12
using namespace std;
ll g[100000];
ll k[1000000],v[1000000];
int tot,cnt,n,tc,i;
ll l,r;
bool cmper(const ll &a,const ll &b)
{return a<b;}
void dfs(int x,int N,ll now)
{
  if (x==N+1) {g[++tot]=now; return;}
  dfs(x+1,N,now*10+4);
  dfs(x+1,N,now*10+7);
}
void work(int x,ll now,double wq)
{
  int i;
  if (now!=1) {cnt++; k[cnt]=now;}
  for(i=x;i<=tot && 1.0*wq*g[i]<=maxo;i++)
    work(i,now*g[i],1.0*wq*g[i]);
}
int count(ll a)
{
  int ls=1; int rs=n;
  while (ls<rs)
    {
      int mid=(ls+rs)>>1;
      if (v[mid]<a) ls=mid+1;
      else rs=mid;
    }
  if (v[ls]<=a) return ls;
  return ls-1;
}
int main()
{
  freopen("prd.in","r",stdin);
  freopen("prd.out","w",stdout);
  for(i=1;i<=12;i++)
    dfs(1,i,0);
  work(1,1,1);
  sort(k+1,k+1+cnt,cmper);
  for(i=1;i<=cnt;i++)
    if (k[i]!=k[i-1]) v[++n]=k[i];
  scanf("%d",&tc);
  for(;tc--;)
    {
      scanf("%lld %lld",&l,&r);
      printf("%d\n",count(r)-count(l-1));
    }
  return 0;
}
