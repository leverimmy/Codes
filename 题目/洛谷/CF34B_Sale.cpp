#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

int n,m;
int a[110],i,j,t,money=0;
	
int main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
	for(i=0;i<m;i++)
		if(a[i]<0)
			money=money+a[i];
    money=-money;
    printf("%d",money);
	return 0;
}
