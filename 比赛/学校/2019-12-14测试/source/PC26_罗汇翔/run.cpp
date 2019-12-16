#include<bits/stdc++.h>
using namespace std;
int n,m;
int e[110][110];
int a,b;
int c;
int p;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)e[i][j]=2147483647;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		e[a][b]=min(e[a][b],c);
		e[b][a]=min(e[b][a],c);
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        for(int k=1;k<=n;k++)
	{
		e[j][k]=min(e[j][k],max(e[j][i],e[i][k]));
	}
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>a>>b;
		cout<<e[a][b]<<endl;
	}
	return 0;
}
