#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	int n,len;
	char a[100009];
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		getchar(); 
		len=strlen(a);
		if(len==1)
		{
			printf("%c\n",a[0]);
		}
		if(len==2)
		{
			printf("%c%c\n",a[0],a[1]);
		}
		else
		{
			if(len==4)
			{
				if(a[2]<a[0])
				{
					printf("%c%c%c%c\n",a[2],a[1],a[0],a[3]);
				}
				else
				{
					printf("%c%c%c%c\n",a[0],a[1],a[2],a[3]);
				}
			}
			if(len==5)
			{
				if(a[2]=='[' && a[4]==']')
				{
					if(a[3]<=a[0])
					{
						printf("%c%c%c%c%c\n",a[3],a[2],a[0],a[1],a[4]);
					}
					else
					{
						printf("%c%c%c%c%c\n",a[0],a[1],a[2],a[3],a[4]);
					}
				}
				if(a[1]=='[' && a[4]==']')
				{
					if(a[2]<a[0])
					{
						printf("%c%c%c%c%c\n",a[2],a[3],a[1],a[0],a[4]);
					}
					else
					{
						printf("%c%c%c%c%c\n",a[0],a[1],a[2],a[3],a[4]);
					}
				}
			}
		}
	}
	return 0;
}

