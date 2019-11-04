#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n,ans=0,i;
int a[1000001];
int count1,count2,count3;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)	
				count1++;
            if(a[i]==2)	
				count2++;
            if(a[i]==3)
				count3++;
        }
    ans=count1;
    if(ans<count2)
		ans=count2;
    if(ans<count3)
		ans=count3;
    printf("%d",n-ans);
	return 0;
}
