#include<cstdio>
#include<ctime>
#include<cstdlib>

const int mt=10,mn=10,mlen=10000;

const int t=10,n=10,len=10000;

int main()
{
	srand(time(NULL));
	freopen("happiness18.in","w",stdout);
	printf("%d\n",t);
	for (int i=1;i<=t;i++)
	{
		printf("%d\n",n);
		for (int j=1;j<=n;j++)
		{
			int nl=len-rand()%1000;
			for (int k=1;k<=nl;k++) printf("a");
			printf("\n");
		}
	}
	return 0;
}
