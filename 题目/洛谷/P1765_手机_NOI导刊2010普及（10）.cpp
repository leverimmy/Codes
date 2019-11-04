#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char c[1000];
	int len,sum=0,i;
	gets(c);
	len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]=='a')	sum=sum+1;
		else if(c[i]=='b')	sum=sum+2;
		else if(c[i]=='c')	sum=sum+3;
		else if(c[i]=='d')	sum=sum+1;
		else if(c[i]=='e')	sum=sum+2;
		else if(c[i]=='f')	sum=sum+3;
		else if(c[i]=='g')	sum=sum+1;
		else if(c[i]=='h')	sum=sum+2;
		else if(c[i]=='i')	sum=sum+3;
		else if(c[i]=='j')	sum=sum+1;
		else if(c[i]=='k')	sum=sum+2;
		else if(c[i]=='l')	sum=sum+3;
		else if(c[i]=='m')	sum=sum+1;
		else if(c[i]=='n')	sum=sum+2;
		else if(c[i]=='o')	sum=sum+3;
		else if(c[i]=='p')	sum=sum+1;
		else if(c[i]=='q')	sum=sum+2;
		else if(c[i]=='r')	sum=sum+3;
		else if(c[i]=='s')	sum=sum+4;
		else if(c[i]=='t')	sum=sum+1;
		else if(c[i]=='u')	sum=sum+2;
		else if(c[i]=='v')	sum=sum+3;
		else if(c[i]=='w')	sum=sum+1;
		else if(c[i]=='x')	sum=sum+2;
		else if(c[i]=='y')	sum=sum+3;
		else if(c[i]=='z')	sum=sum+4;
		else if(c[i]==' ')	sum=sum+1;
	}
	printf("%d",sum);
	getchar();getchar();
	return 0;
}