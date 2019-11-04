#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int n,i,j;
int A[1010],B[1010];
int lena,lenb;

int main()
{
	freopen("serial.in","r",stdin);
	freopen("serial.out","w",stdout);
	scanf("%d",&n);
	i=n*4/5;
	while(i!=0)
	{
		i=n*4/5;
		j=n*3/7;
		int ti=i,tj=j;
		A[++lena]=ti;
		B[++lenb]=tj;
		n=i;
	}
	for(int k=1;k<=lena;k++)
		printf("%d",A[k]);
	for(int k=lenb;k>=1;k--)
	{
		if(B[k]==0)
			printf("0");
		while(B[k]>0)
		{
			printf("%d",B[k]%10);
			B[k]/=10;
		}
	}
	return 0;
}