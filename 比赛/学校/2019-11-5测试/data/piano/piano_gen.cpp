#include<cstdio>
#include<ctime>
#include<cstdlib>

const int n=25,m=50,p=10;
const char a[n+1]={' ','q','w','e','r','t','y','a','s','d','f','g','h','j','k','l','z','x','c','v','b','u','i','o','p','m'};

int main()
{
	srand(time(NULL));
	freopen("piano20.in","w",stdout);
	printf("%d %d %d\n",n,m,p);
	for (int i=1;i<=n;i++) printf("%c",a[i]);
	printf("\n");
	for (int i=1;i<=p;i++)
	{
		int len=rand()%(m-1)+1;
		for (int j=1;j<=len;j++) printf("%c",a[rand()%n+1]);
		printf("\n");
	}
	return 0;
}
