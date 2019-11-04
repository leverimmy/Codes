#include <cstdio>

using namespace std;

int a[100010]={0,1},b[100010]={0,2},c[100010]={0},x=0,len=1,n,flag=1;

int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		printf("%d",n);
		flag=0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=len;j++)	c[j]=a[j]+b[j];
		for(int j=1;j<=len;j++)
		{
			if(c[j]>9)
			{
				c[j+1]+=c[j]/10;
				c[j]=c[j]%10;
				if(j-len+1>0)	len++;
			}
		}
		for(int j=1;j<=len;j++)
			a[j]=b[j];
		for(int j=1;j<=len;j++)
			b[j]=c[j];
	}
	if(flag)
	{
		while(b[len]==0 && len>=2)
			len--;
		for(int i=len;i>=1;i--)
			printf("%d",b[i]);
	}
	return 0;
}