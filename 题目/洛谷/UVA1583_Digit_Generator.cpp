#include <cstdio>

int t,n,ans[100010];

int getsum(int number)
{
	int sum=0;
	while(number)
	{
		sum+=number%10;
		number/=10;
	}
	return sum;
}

void init()
{
	for(int i=100000;i>=1;i--)
	{
		int num=getsum(i);
		ans[num+i]=i;
	}
}

int main()
{
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}