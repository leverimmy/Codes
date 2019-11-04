#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int f[450][100010];
int main()
{	freopen("fiorentina.in","r",stdin);
		freopen("fiorentina.out","w",stdout);
	int n,p;
	scanf("%d%d",&n,&p);
	int i,j,ans=0;
	f[0][0]=1;
	for(i=1;(i+1)*i/2<=p;i++)
	{
		for(j=i;j<=p;j++)
		{
			f[i][j]=f[i-1][j-i]+f[i][j-i];
			if(j>=(n+1)) f[i][j]-=f[i-1][j-(n+1)];
			if(f[i][j]<0) f[i][j]+=mod;
			if(f[i][j]>=mod) f[i][j]-=mod;
		}
		ans+=f[i][p];
		if(ans>=mod) ans-=mod;
	}
	printf("%d",ans);
}
