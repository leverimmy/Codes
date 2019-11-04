#include <cstdio>

using namespace std;

long long n,ans;
long long a[100010];

int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=2;i<=n;i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%lld",ans+a[1]);
	return 0;
}

