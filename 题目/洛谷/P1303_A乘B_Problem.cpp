#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	char a1[3000],b1[3000];
	int a[3000],b[3000],c[3000],lena,lenb,lenc,x,i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%s",a1);
	scanf("%s",b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(i=0;i<=lena-1;i++)
		a[lena-i]=a1[i]-48;
	for(i=0;i<=lenb-1;i++)
		b[lenb-i]=b1[i]-48;
	for(i=1;i<=lena;i++)
	{
		x=0;
		for(j=1;j<=lenb;j++)
		{
			c[i+j-1]+=a[i]*b[j]+x;
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=x;
	}
	lenc=lena+lenb;
	while(c[lenc]==0 && lenc>1)
		lenc--;
	for(i=lenc;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}