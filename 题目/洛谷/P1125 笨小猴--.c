#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int prime(int n)
{
	int i,flag=1;
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)
			flag=0;
    if(n<2)
		flag=0;
    return flag;
}
int main()
{
	char a[26]={0};
    char word[1000];
    int i,max,min,p,len;
    gets(word);
    len=strlen(word);
    for(i=0;i<len;i++)
		if(word[i]>='a')
			a[word[i]-97]++;
        if(word[i]<='Z')
			a[word[i]-65]++;
    max=0;
    min=100;
    for(i=0;i<26;i++)
		if(a[i]>=max)
			max=a[i];
    for(i=0;i<26;i++)        
        if((a[i]<=min)&&(a[i]>0))
			min=a[i];
    //printf("%d %d",max,min);
    p=max-min;
    if(prime(p)==1)
		printf("Lucky Word\n%d",p);
    else
		printf("No Answer\n0");
	system("pause");
	return 0;
}
