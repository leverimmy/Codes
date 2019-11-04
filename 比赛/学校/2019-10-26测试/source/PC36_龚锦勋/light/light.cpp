#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int l[100000],ps[100000];

//Ïß¶ÎÊ÷ 

int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
	}
	if(n<700 && m<700)
	{
		
		for(int i=0;i<m;i++)
		{
			int xl,r,p,v;
			scanf("%d%d%d%d",&xl,&r,&p,&v);
			int c=0;
			for(int j=xl-1;j<r;j++)
			{
				if(l[j]%p==v)
				{
					c++;
				}
			}
			printf("%d\n",c);
		}
	}
	else //pÏàµÈ 
	{
		int xl,r,p,v,c=0;
		scanf("%d%d%d%d",&xl,&r,&p,&v);
		for(int i=0;i<n;i++)
		{
			ps[i] = l[i]%p;
		}
		for(int j=xl-1;j<r;j++)
		{
			if(ps[j]==v)
			{
				c++;
			}
		}
		printf("%d\n",c);
		for(int i=0;i<m;i++)
		{
			c=0;
			scanf("%d%d%d%d",&xl,&r,&p,&v);
			for(int j=xl-1;j<r;j++)
			{
				
				if(ps[j]==v)
				{
					c++;
				}
			}
			printf("%d\n",c);
		}
	}
	return 0;
}
