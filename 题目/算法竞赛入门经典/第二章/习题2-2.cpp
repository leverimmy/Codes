#include <cstdio>
#include <cstdlib>

using namespace std;

int a,b,c,num,flag=0;
int count=1;
int main()
{
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		printf("Case %d: ",count);
		count++;
		for(num=10;num<=100;num++)
			if(num%3==a && num%5==b && num%7==c)
			{
				printf("%d\n",num);
				flag=1;
			}
		if(!flag)
			printf("No answer\n");
		flag=0;
	}
	return 0;
}