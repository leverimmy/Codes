#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10-48+ch;ch=getchar();}
	return x*f;
}
const int inf=0x3f3f3f3f;
const int maxn=1005;
int num[maxn][maxn];
int n,m,ans=inf;
bool check[maxn][maxn];
void dfs(int x,int y,int qwq)
{
	if(x==n&&y==m)
	{
		ans=min(ans,qwq);
		return;
	}
	if(x<n)
	{
		int d=qwq;bool j1=0,j2=0,j3=0,j4=0,j5=0;
		if(!check[x][y])
		{
			qwq+=num[x][y];
			check[x][y]=1;
			j1=1;
		}
		if(!check[x+1][y])
		{
			qwq+=num[x+1][y];
			check[x+1][y]=1;
			j2=1;
		}
		if(!check[x+1][y-1])
		{
			qwq+=num[x+1][y-1];
			check[x+1][y-1]=1;
			j3=1;
		}
		if(!check[x+1][y+1])
		{
			qwq+=num[x+1][y+1];
			check[x+1][y+1]=1;
			j4=1;
		}
		if(!check[x+2][y])
		{
			check[x+2][y]=1;
			qwq+=num[x+2][y];
			j5=1;
		}
		dfs(x+1,y,qwq);
		qwq=d;
		if(j1)check[x][y]=0;
		if(j2)check[x+1][y]=0;
		if(j3)check[x+1][y-1]=0;
		if(j4)check[x+1][y+1]=0;
		if(j5)check[x+2][y]=0;
	}
	if(y<m)
	{
		int d=qwq;bool j1=0,j2=0,j3=0,j4=0,j5=0;
		if(!check[x][y])
		{
			qwq+=num[x][y];
			check[x][y]=1;
			j1=1;
		}
		if(!check[x-1][y+1])
		{
			qwq+=num[x-1][y+1];
			check[x-1][y+1]=1;
			j2=1;
		}
		if(!check[x][y+1])
		{
			qwq+=num[x][y+1];
			check[x][y+1]=1;
			j3=1;
		}
		if(!check[x+1][y+1])
		{
			qwq+=num[x+1][y+1];
			check[x+1][y+1]=1;
			j4=1;
		}
		if(!check[x][y+2])
		{
			check[x][y+2]=1;
			qwq+=num[x][y+2];
			j5=1;
		}
		dfs(x,y+1,qwq);
		qwq=d;
		if(j1)check[x][y]=0;
		if(j2)check[x-1][y+1]=0;
		if(j3)check[x][y+1]=0;
		if(j4)check[x+1][y+1]=0;
		if(j5)check[x][y+2]=0;
	}
}
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			num[i][j]=read();
			if(!num[i][j])check[i][j]=1;
		}
	check[1][1]=1;
	check[2][1]=1;
	check[1][2]=1;
	dfs(1,1,num[1][1]+num[2][1]+num[1][2]);
	cout<<ans<<'\n';
	return 0;
}
