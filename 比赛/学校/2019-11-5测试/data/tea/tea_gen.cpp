#include<cstdio>
#include<cstdlib>
#include<ctime>

const int n=2000,len=20000;
const char ch[8]={'Q','W','e','r','J','K','h','y'};

int main()
{
	srand(time(NULL));
	freopen("tea9.in","w",stdout);
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=len;j++) printf("%c",ch[rand()%8]);
		printf("\n");
	}
	return 0;
}

