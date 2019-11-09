#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,a[200005],b[200005],ans;
int read()
{
	int x=0,f=0;
	char ch;
	while(!isdigit(ch=getchar()))
		if(ch=='-')
			f=1;
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	if(f)
		return -x;
	else
		return x;
}
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	b[0]=-2;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			for(int k=1;k<=n;k++)
			{
				b[k]=a[k];
			}
			for(int k=1;k<=j;k++)
			{
				b[i+k-1]=-1;
			}
			int len=0;
			for(int k=1;k<=n;k++)
			{
				if(b[k]==-1)
				{
					continue;
				}
				if(b[k-1]==-1)
				{
					if(b[k]>b[k-j-1])
					{
						len++;
						ans=max(ans,len);
					}
					else
					{
						len=1;
					}
				}
				else
				{
					if(b[k]>b[k-1])
					{
						len++;
						ans=max(ans,len);
					}
					else
					{
						len=1;
					}
				}
			}
		}
	}
	cout<<ans;
}
