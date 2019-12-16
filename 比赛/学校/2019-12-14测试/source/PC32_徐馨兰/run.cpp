#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,m;
int f[500][500];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		f[u][v]=f[v][u]=min(f[u][v],w);
	}
	int p=read();
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			}
		}
	}
	for(int i=1;i<=p;i++)
	{
		int a=read(),b=read();
		cout << f[a][b] << endl;
	}
	return 0;
} 
