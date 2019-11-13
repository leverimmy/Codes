#include<cstdio>
#define maxn 500050
using namespace std;
int n,len,dt[maxn];
int l,r,ans,i;
int main()
{
  freopen("clean.in","r",stdin);
  freopen("clean.out","w",stdout);
  scanf("%d %d",&len,&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d %d",&l,&r);
      dt[l]++; dt[r+1]--;
    }
  for(i=1;i<=len;i++)
    dt[i]+=dt[i-1];
  for(i=1;i<=len;i++)
    if (!dt[i]) ans++;
  printf("%d",ans);
  return 0;
}
