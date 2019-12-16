#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
const int inf=453266144,F1[4]={0,0,1,-1},F2[4]={1,-1,0,0};
int a[20][20],ans,V[20][20],dp[17][17][1<<7],b[3005],d[20][20],c[305],n,m,K,i,j,T,S,sum,k,r,l,nowx,nowy;
bool v[20][20];
struct node {int x,y,z;} st[1000005];
int cmp(node i,node j) {return i.z>j.z;}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    srand(10086);
    ans=inf;
    scanf("%d%d%d",&n,&m,&K);
    for (i=1; i<=n; i++)
      for (j=1; j<=m; j++)
      {
        scanf("%d",&a[i][j]);
        if (a[i][j]!=-1) a[i][j]++;
        assert(a[i][j]>=-1 && a[i][j]<=n*m);
      }
    for (i=1; i<=n; i++)
      for (j=1; j<=m; j++)
        scanf("%d",&V[i][j]);
    T=380; sum=n*m;
    for (i=1; i<=sum; i++) b[i]=i;
    for (i=0; i<=n+1; i++) for (j=0; j<=m+1; j++) if (i<=0 || i>n || j<=0 || j>m) d[i][j]=-1;
    while (T--)
    {
       random_shuffle(b+1,b+n*m+1);
       for (i=1; i<=K; i++) c[b[i]]=i;
       for (i=K+1; i<=sum; i++) c[b[i]]=rand()%K+1;
       for (i=1; i<=n; i++) for (j=1; j<=m; j++) d[i][j]=c[a[i][j]]-1;
       S=(1<<K);
       for (i=1; i<=n; i++) for (j=1; j<=m; j++) for (k=0; k<S; k++) dp[i][j][k]=inf;
       for (i=1; i<=n; i++)
         for (j=1; j<=m; j++)
           if (d[i][j]>=0) dp[i][j][1<<d[i][j]]=V[i][j];
      for (i=1; i<S; i++)
      {
          for (l=(i-1&i); l+l>i; l=(l-1&i))
            for (j=1; j<=n; j++)
              for (k=1; k<=m; k++)
                dp[j][k][i]=min(dp[j][k][i],dp[j][k][l]+dp[j][k][i^l]-V[j][k]);
          r=0;
          for (j=1; j<=n; j++) for (k=1; k<=m; k++) v[j][k]=false;
          for (j=1; j<=n; j++)
            for (k=1; k<=m; k++)
              if (dp[j][k][i]<ans)
              {
                st[++r].x=j; st[r].y=k;
                v[j][k]=true;
              }
          l=0;
          while (l!=r)
          {
              nowx=st[++l].x; nowy=st[l].y;
              for (j=0; j<4; j++)
                if (d[nowx+F1[j]][nowy+F2[j]]>=0 && dp[nowx][nowy][i]+V[nowx+F1[j]][nowy+F2[j]]<ans && dp[nowx+F1[j]][nowy+F2[j]][i]>dp[nowx][nowy][i]+V[nowx+F1[j]][nowy+F2[j]])
                {
                    dp[nowx+F1[j]][nowy+F2[j]][i]=dp[nowx][nowy][i]+V[nowx+F1[j]][nowy+F2[j]];
                    if (!v[nowx+F1[j]][nowy+F2[j]]) {st[++r].x=nowx+F1[j]; st[r].y=nowy+F2[j];v[nowx+F1[j]][nowy+F2[j]]=true;}
                }
              v[nowx][nowy]=false;
          }
          for (j=1; j<=n; j++) for (k=1; k<=m; k++)
            for (l=0; l<4; l++)
              if (d[j+F1[l]][k+F2[l]]>=0 && dp[j+F1[l]][k+F2[l]][i|(1<<d[j+F1[l]][k+F2[l]])]>dp[j][k][i]+V[j+F1[l]][k+F2[l]])
                dp[j+F1[l]][k+F2[l]][i|(1<<d[j+F1[l]][k+F2[l]])]=dp[j][k][i]+V[j+F1[l]][k+F2[l]];
      }
      for (j=1; j<=n; j++) for (k=1; k<=m; k++) ans=min(ans,dp[j][k][S-1]);
    }
    if (ans==inf) puts("-1"); else
    cout<<ans<<endl;
    return 0;
}
