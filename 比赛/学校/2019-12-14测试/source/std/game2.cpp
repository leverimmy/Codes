#include<cstdio>
#include<algorithm>
using namespace std;
int f[8220][22],g[8220][22];
int n,s,a[50],i,j,can,go;
int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  while (scanf("%d",&n),n)
    {
      scanf("%d",&s);
      for(i=1;i<=2*n;i++)
	scanf("%d",&a[i]);
      for(i=1;i<=2*n;i++)
	f[0][i]=1,g[0][i]=(1<<10)-1;
      for(i=1;i<=s;i++)
	for(j=1;j<=2*n;j++){
	  can=10-a[j]; go=j%(2*n)+1;
	  f[i][j]=((g[i-1][go]>>can)!=((1<<a[j])-1));
	  g[i][j]=(g[i-1][j]>>1)+(f[i][j]<<9);
	}
      printf("%d\n",f[s][1]);
    }
  return 0;
}
