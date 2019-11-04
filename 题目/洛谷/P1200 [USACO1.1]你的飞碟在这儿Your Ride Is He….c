#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[7];
    char b[7];
    int lena,lenb;
    int suma=1,sumb=1;
    int i,ra,rb;
    gets(a);
    gets(b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
		suma=suma*(int)(a[i]-64); 
    for(i=0;i<lenb;i++)
		sumb=sumb*(int)(b[i]-64);
    ra=suma%47;
    rb=sumb%47;
    if(ra==rb)
		printf("GO");
    else
		printf("STAY");
	//system("pause");
	return 0;
}
