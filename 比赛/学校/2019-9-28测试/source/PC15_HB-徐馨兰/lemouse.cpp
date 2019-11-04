#include <bits/stdc++.h>
using namespace std;

const int INF=99999999;

int n,m;
int a[1010][1010],xn1[1010],ym1[1010],xn2[1010],ym2[1010],f[1010][1010];
long long ans=INF;

int read()
{
	char ch=getchar();int res=0,p=1;
	while(!isdigit(ch)) { if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

void dfs(int x,int y,long long num)
{
	if(x>n || y>m) return ;
	if(num>=ans) return ;
	int a1=a[x-1][y],a2=a[x][y-1],a3=a[x+1][y],a4=a[x][y+1];
	num+=a[x-1][y]+a[x][y-1]+a[x+1][y]+a[x][y+1];
	if(x==n && y==m) {ans=min(num,ans);return;}
	if(x==n)
	{
		num+=xn1[y+1]-a[n][y+1];
		ans=min(ans,num);
		return ;
	}
	if(y==m)
	{
		num+=ym1[x+1]-a[x+1][m];
		ans=min(ans,num);
		return ;
	}
	a[x-1][y]=a[x][y-1]=a[x+1][y]=a[x][y+1]=0;
	dfs(x+1,y,num);dfs(x,y+1,num);
	a[x-1][y]=a1,a[x][y-1]=a2,a[x+1][y]=a3,a[x][y+1]=a4;
}

/*long long dfs(int x,int y)
{
	if(f[x][y]!=-1)
		return f[x][y];
	if(x==n) return f[x][y]=xn1[y+1]+a[x][y];
	if(y==m) return f[x][y]=ym1[x+1]+a[x][y];
	return f[x][y]=a[x][y]+min(dfs(x+1,y),dfs(x,y+1));
}*/

int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read(),f[i][j]=-1;
	xn1[m]=ym1[n]=a[n][m];
	xn2[m]=a[n][m]+a[n-1][m],ym2[n]=a[n][m]+a[n][m-1];
	for(int i=m-1;i>=1;i--) xn1[i]=xn2[i+1]+a[n][i],xn2[i]=xn1[i]+a[n-1][i]+a[n][i];
	for(int j=n-1;j>=1;j--) ym1[j]=ym2[j+1]+a[j][m],ym2[j]=ym1[j]+a[j][m-1]+a[j][m];
	dfs(1,1,0);
	printf("%lld\n",ans);
	return 0;
}
