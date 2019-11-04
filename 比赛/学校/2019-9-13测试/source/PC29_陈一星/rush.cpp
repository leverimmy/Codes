#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<set>
#define M 2010000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
int n,m,no1[M],no2[M],ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1,s=getchar();} 
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=read();m=read();
	ans=2*n;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (!no1[x]) ans--;
		if (!no2[y]) ans--;
		no1[x]=1;no2[y]=1;
	}
	printf("%d",ans);
    return 0;
}


