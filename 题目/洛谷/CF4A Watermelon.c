#include <stdio.h>
#include <stdlib.h>
int even(int x)
{
	if(x%2==0)
		return 1;
    else
		return 0;
}				
int main()
{
	int n,flag=0;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n/2;i++)
		if((even(i)==1)&&(even(n-i)==1))
			flag=1;
    if(flag==1)
		printf("Yes");
    else
		printf("No");
	system("pause");
	return 0;
}
