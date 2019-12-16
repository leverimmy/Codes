#include<cstdio>
#include<algorithm>
#define seed 13171
#define maxn 500050
#define ll unsigned long long
using namespace std;
ll hs[maxn],sd[maxn];
char st[maxn];
int n,m,i,x,y;
int judge(int x,int y)
{
  int l1=n-x+1; int l2=n-y+1;
  int ls,rs,mid;
  ll h1,h2;
  ls=0; rs=min(l1,l2);
  while (ls<rs)
    {
      mid=(ls+rs)/2+1;
      h1=hs[x+mid-1]-hs[x-1]; h1*=sd[n-x];
      h2=hs[y+mid-1]-hs[y-1]; h2*=sd[n-y];
      if (h1==h2) ls=mid;else rs=mid-1;
    }
  if (ls==min(l1,l2)) return !(l1<l2);
  return !(st[x+ls]<st[y+ls]);
}
int main()
{
  freopen("lcp.in","r",stdin);
  freopen("lcp.out","w",stdout);
  scanf("%d %d\n",&n,&m); 
  scanf("%s",st+1);
  for(sd[0]=1,i=1;i<=n;i++)
    sd[i]=sd[i-1]*seed;
  for(i=1;i<=n;i++)
    hs[i]=hs[i-1]+sd[i]*st[i];
  for(;m--;)
    {
      scanf("%d %d",&x,&y);
      printf("%d\n",judge(x,y));
    }
  return 0;
}
