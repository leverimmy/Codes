#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> f[100005],g[100005];
int n,m,x,y,z,F[100005],ans,visit[100005],q[100005];
void spfa()
{
	int head=1,tail=1,t=0;
	visit[1]=1;
	q[head]=1;
	while (head<=tail)
	 {
	 	t=q[head];
	 	++head;
	 	visit[t]=0;
	 	for (int i=0;i<f[t].size();i++)
	 	 {
	 	 int sum=max(g[t][i],F[t]);
	 	 if (sum<F[f[t][i]]) 
	 	 {
	 	 	F[f[t][i]]=sum;
	 	 	if (!visit[f[t][i]]) 
	 	 	{ q[++tail]=f[t][i]; visit[f[t][i]]=1; }
	 	 }
	 }
	 }
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d%d",&x,&y,&z);
	 	f[x].push_back(y);
	 	f[y].push_back(x);
	 	g[x].push_back(z);
	 	g[y].push_back(z);
	 }
	for (int i=1;i<=n;i++)
	 F[i]=1e9;
	F[1]=0;
	spfa();
	for (int i=2;i<=n;i++)
	 ans+=F[i];
	cout<<ans;
	return 0;
}
