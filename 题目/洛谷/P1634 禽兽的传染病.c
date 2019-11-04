#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int x,n,ans=1,i;
	scanf("%lld %lld",&x,&n);
	for(i=1;i<=n;i++)
		ans=ans+ans*x;
	printf("%lld",ans);
    //system("pause");
	return 0;
}
