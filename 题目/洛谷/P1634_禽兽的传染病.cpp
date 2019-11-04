#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long int x,n,ans=1,i;
	scanf("%lld %lld",&x,&n);
	for(i=1;i<=n;i++)
		ans=ans+ans*x;
	printf("%lld",ans);
	return 0;
}