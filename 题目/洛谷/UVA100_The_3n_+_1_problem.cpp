#include <cstdio>

using namespace std;

int i,j;

int countx(int num,int cnt)
{
	if(num==1)
		return cnt;
	else if(num%2==1)
		num=3*num+1;
	else if(num%2==0)
		num=num/2;
	return countx(num,cnt+1);
}

int main()
{
	while(scanf("%d %d",&i,&j)==2)
	{
		printf("%d %d",i,j);
		if(i>=j)
			i^=j^=i^=j;
		int max=-1000000;
		for(int k=i;k<=j;k++)
			if(max<countx(k,1))
				max=countx(k,1);
		printf(" %d\n",max);
	}
	return 0;
}