#include <cstdio>
#include <cmath>
#define root 2.20556943
#define c 0.460719842
#define MOD 10007

using namespace std;

double base=1.00;
int ans,n;
int a[1010]={1,1,2,5,11};

int round(int num){return num>0.5?ceil(num):floor(num);}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		base*=root;
	}
	ans=round(c*base);
	ans%=10007;
	printf("%d",ans);
	/*for(int i=5;i<=n;i++)
		a[i]=(9*a[i-3]%MOD+2*a[i-4]%MOD+4*a[i-5]%MOD)%MOD;*/
	return 0;
}

