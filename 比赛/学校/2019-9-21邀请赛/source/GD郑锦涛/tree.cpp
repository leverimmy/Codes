#include<bits/stdc++.h>
using namespace std;
int sum,ans[100005],ma,n,m;
struct data{int v,c;};
vector <data>G[100005];
void Go(int u,int k,int fa)
{	 
  if (ma<ans[u]&&ans[u]!=0) ans[u]=ma;	
  if (ans[u]==0) ans[u]=ma;
  if (ma>ans[u]) return;
  for (int i=0;i<G[u].size();i++)
   {
   	  if (G[u][i].c>ma)ma=G[u][i].c;
   	  if (G[u][i].v==fa)continue;
   	  if (k>n)break;
   	  Go(G[u][i].v,k+1,u);
   }
}
int main()
{
   freopen("tree.in","r",stdin);
   freopen("tree.out","w",stdout);	
   cin>>n>>m;
   for (int i=1;i<=m;i++)
   {
   	 int u,v,c;
   	 scanf("%d%d%d",&u,&v,&c);
   	 data a;
   	 a.v=v;a.c=c;
   	 G[u].push_back(a);
   	 a.v=u;
   	 G[v].push_back(a);
   }
   for (int i=0;i<G[1].size();i++)
   {
   	 ma=G[1][i].c; 
     Go(G[1][i].v,1,1);
   } 
   for (int i=2;i<=n;i++)
     sum+=ans[i];
   cout<<sum;
   return 0;	
}
