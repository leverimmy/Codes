#include<cstdio>
#define N 500005
inline int read()
{
	register int x=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=getchar();
	}
	return x;
}
int n,m;
int a[N],sum[N];
bool flag;
int all;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1)
		{
			sum[a[i]]++;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(sum[i]==n)
		{
			flag=true,all=i;
		}
	}
	m=read();
	int p,k,ans;
	for(register int i=1;i<=m;i++)
	{
		ans=0,p=read(),k=read();
		if(flag==true)
		{
			printf("%d\n",(n-p)/(all+k)+1);
			continue;
		}
		while(p<=n)
		{
			p+=(a[p]+k);
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
