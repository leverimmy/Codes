#include<cstdio>
#include<ctime>
#include<cstdlib>

const int x=10,n=3,m=99999,p=4,maxt=23333;

int main()
{
	srand(time(NULL));
	freopen("journey6.in","w",stdout);
	printf("%d",x);
	for (int k=1;k<=x;k++) 
	{
		printf("%d %d\n",n,m);
		for (int i=1;i<=m;i+=3) printf("%d 1 2 2\n%d 2 3 2\n%d 3 1 2\n",i,i+1,i+2);
		printf("%d\n2 3 2 3\n",p);
		printf("%d\n",maxt);
	}
	return 0;
}
