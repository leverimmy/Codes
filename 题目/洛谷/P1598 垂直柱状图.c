#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int time[26];
int main()
{
    int maxtime=0,i,j,len;
    char a[110];
    for(i=0;i<4;i++)
	{
		gets(a);
        len=strlen(a);
        for(j=0;j<len;i++)
			if(a[j]>='A' && a[j]<='Z')
				time[a[j]-65]++;
    }
    for(i=0;i<26;i++)
		if(time[i]>maxtime)
			maxtime=time[i];
    for(i=maxtime;i>0;i--)
		{
			for(j=0;j<26;j++)
				if(time[j]>i)
					//{
						printf("* ");
                    //    time[j]--;
                    //}
				else
					printf("  ");
         printf("\n");
		}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	system("pause");
	return 0;
}
