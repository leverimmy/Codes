#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[100];
    char b[100];
    int len,team1=0,team2=0,i;
    scanf("%s",a);
    scanf("%s",b);
    len=strlen(a);
    for(i=0;i<len;i++)
	{
		if(a[i]=='8' && b[i]=='(')
			team2++;
        if(b[i]=='8' && a[i]=='(')
			team1++;
        if(a[i]=='8' && b[i]=='[')
			team1++;
        if(b[i]=='8' && a[i]=='[')
			team2++;
        if(a[i]=='(' && b[i]=='[')
			team2++;
        if(b[i]=='(' && a[i]=='[')
			team1++;
    }
    if(team1==team2)
		printf("TIE");
    if(team1>team2)
		printf("TEAM 1 WINS");
    if(team2>team1)
		printf("TEAM 2 WINS");
	system("pause");
	return 0;
}
