#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char m[100],n[100];
    int a[100],b[100],c[100];
    int lena,lenb,lenc,x,i;
	memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    //gets(m);
    //gets(n);
    scanf("%s",m);
    scanf("%s",n);
    lena=strlen(m);
    lenb=strlen(n);
    for(i=0;i<lena;i++)
		a[lena-i]=m[i]-48;
    for(i=0;i<lenb;i++)
		b[lenb-i]=n[i]-48;
    lenc=1;
    x=0;
    while((lenc<=lena)||(lenc<=lenb))
		{
			c[lenc]=a[lenc]+b[lenc]+x;
            x=c[lenc]/10;
            c[lenc]=c[lenc]%10;
            lenc++;
        }
    c[lenc]=x;
    if(c[lenc]==0)
		lenc--;
    for(i=lenc;i>0;i--)
		printf("%d",c[i]);
	system("pause");
	return 0;
}
