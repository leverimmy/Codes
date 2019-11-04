#include <cstdio>
#include <cmath>
#define MOD 10007

using namespace std;

int n;

long long ksm(long long base,long long power)
{
	long long r=1;
	while(power>0)
	{
		if(power&1)
			r=r*base%MOD;
		base=base*base%MOD;
		power>>=1;
	}
	return r;
}

int main()
{
	
	return 0;
}