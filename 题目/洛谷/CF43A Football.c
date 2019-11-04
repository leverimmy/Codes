#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,x=0;
    char a[1000][1000];
    int Adui=0,Bdui=0;
    scanf("%d",&n);
    scanf("%s",a[0]);
    for(i=1;i<n;i++)
		{
			scanf("%s",a[i]);
			if(a[i]==a[i-1])
				Adui++;
			else
				{
					x=i;
                    Bdui++;
                }
        }
    if(Adui>Bdui)
		printf("%s",a[0]);
    else
		printf("%s",a[x]);
	system("pause");
	return 0;
}
