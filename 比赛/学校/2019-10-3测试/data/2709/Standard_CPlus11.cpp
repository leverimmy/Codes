#include<bits/stdc++.h>
#define N 1010
#define M 100010
using namespace std;
int n,m,f[N][2],t[N][2],q[N*2],p[N*2],ans[N][N];
int A[M],B[M];
vector<int>to[N];
void work(int S)
{
  int l=1,r=1;
  for(int i=1;i<=n;i++)
    for(int j=0;j<=1;j++)f[i][j]=-1,t[i][j]=0;
    for (int i=0;i<to[S].size();i++)
	{
      q[r]=to[S][i];p[r]=0;
      f[q[r]][0]=1;
      t[q[r]][0]=to[S][i];
      r++;
    }
  while(l<r)
  {
    int x=q[l],y=p[l];l++;
    for(int i=0;i<to[x].size();i++)
    {
      if(to[x][i]==S)continue;
      if(f[to[x][i]][0]==-1)
      {
        f[to[x][i]][0]=f[x][y]+1;
        t[to[x][i]][0]=t[x][y];
        q[r]=to[x][i];p[r]=0;r++;
      }
      else
      {
        if(f[to[x][i]][1]!=-1||t[to[x][i]][0]==t[x][y])continue;
        f[to[x][i]][1]=f[x][y]+1;
        t[to[x][i]][1]=t[x][y];
        q[r]=to[x][i];p[r]=1;r++;
      }
    }
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&A[i],&B[i]);
    to[A[i]].push_back(B[i]);
  }
  for(int i=1;i<=n;i++)
  {
    work(i);
    for(int j=1;j<=n;j++)ans[i][j]=f[j][1];
  }
  for(int i=1;i<=m;i++)
    printf("%d ",ans[A[i]][B[i]]);
  printf("\n");
  return 0;
}
