#include <cstdio>
#include <cmath>
#define MOD 10007

using namespace std;

int ans,n;
int a[1010]={1,1,2};

int main()
{
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
	{
		a[i%4]=2*a[(i-1)%4]%MOD+a[(i-3)%4]%MOD;
	}
	printf("%d",a[n%4]);
	return 0;
}

