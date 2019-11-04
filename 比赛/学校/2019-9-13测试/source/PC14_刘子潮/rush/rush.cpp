#include<cstdio>
const int N=100005;
inline int read()
{
	char ch=getchar();
	int x=0;
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
bool a[N],b[N],c[N],d[N];
int ans;
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=read(),m=read();
	int x,y;
	for(register int i=1;i<=m;i++)
	{
		x=read(),y=read(),a[x]=c[x]=b[y]=d[y]=true;
	}
	for(register int i=1;i<=n;i++)
	{
		if(a[i]==false && b[i]==false)
		{
			b[i]=true;
		}
		if(d[i]==false && a[n-i+1]==false)
		{
			a[n-i+1]=true;
		}
		if(c[i]==false && b[n-i+1]==false)
		{
			c[i]=true;
		}
		if(c[i]==false && d[i]==false)
		{
			d[i]=true;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if((a[i]==false || c[i]==false) || (b[i]==false || d[i]==false))
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
