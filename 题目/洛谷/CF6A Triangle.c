#include <stdio.h>
#include <stdlib.h>
int tri(int a,int b,int c)
{
	if((a+b>c)&&(a+c>b)&&(c+b>a))
		return 2;
    else
		if((a+b==c)||(a+c==b)||(c+b==a))
			return 1;
    return 0;
}
int main()
{
	int x,y,z,w,t,s,i;
    t=s=i=0;
    scanf("%d%d%d%d",&x,&y,&z,&w);
    if(tri(x,y,z)==2)	t++;
    else if(tri(x,y,z)==1)	s++;
    else if(tri(x,y,z)==0)	i++;
    if(tri(x,y,w)==2)	t++;
    else if(tri(x,y,w)==1)	s++;
    else if(tri(x,y,w)==0)	i++;
    if(tri(x,z,w)==2)	t++;
    else if(tri(x,z,w)==1)	s++;
    else if(tri(x,z,w)==0)	i++;
    if(tri(y,z,w)==2)	t++;
	else if(tri(y,z,w)==1)	s++;
    else if(tri(y,z,w)==0)	i++;
    if(t>=1)
		printf("TRIANGLE");
    else
		if(s>=1)
			printf("SEGMENT");
        else
			printf("IMPOSSIBLE");
	system("pause");
	return 0;
}
