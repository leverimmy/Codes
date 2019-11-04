#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int a[11000],b[11000],c[11000],lena,lenb,lenc,i;
char n[11000],n1[11000],n2[11000];

int main()
{
	scanf("%s",n1);
	scanf("%s",n2);
	if(strlen(n1)<strlen(n2)||(strlen(n1)==strlen(n2)&&strcmp(n1,n2)<0))
	{
		strcpy(n,n1);
		strcpy(n1,n2);
		strcpy(n2,n);
		printf("-");
	}
	lena=strlen(n1);
	lenb=strlen(n2);
	for(i=0;i<=lena-1;i++)
		a[lena-i]=n1[i]-'0';
	for(i=0;i<=lenb-1;i++)
		b[lenb-i]=n2[i]-'0';
	i=1;
	while(i<=lena||i<=lenb)
	{
		if(a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	lenc=i;
	while((c[lenc]==0)&&(lenc>1))
		lenc--;
	for(i=lenc;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}