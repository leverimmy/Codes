#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define int long long
using namespace std;
const int maxn=50005;
int n,m1,m2,sum,ans1,ans2;
int g[maxn],f[maxn],h[maxn];

bool cmp(int a,int b)
{
	return a>b;
}

void rep()
{
	memset(f,0,sizeof(f));
	memset(g,0x3f3f3f,sizeof(g));
	g[0]=0;
}

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=n;i++)
		h[i]=read();
	rep();
	for(int i=1;i<=n;i++)
	{
		f[i]=upper_bound(g+1,g+ans1+1,h[i])-g;
		g[f[i]]=h[i];
		ans1=max(ans1,f[i]);
	}
	rep();
	for(int i=1;i<=n;i++)
	{
		f[i]=upper_bound(g+1,g+ans2+1,h[i],cmp)-g;
		g[f[i]]=h[i];
		ans2=max(ans2,f[i]);
	}
	printf("%lld\n",n-max(ans1,ans2));
	return 0;
}
/*
6 1 1
1 4 5 3 2 3
*/
