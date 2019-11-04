#include <bits/stdc++.h>
using namespace std;

long long cnt;
void GCD(long long x,long long y)
{
	if(y==0)
	{
		return;
	}
	cnt+=x/y;
	x%=y;
	GCD(y,x);
}

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	long long a,b;
	scanf("%lld%lld",&a,&b);
	if(a==0&&b==0)
	{
		printf("1");
		return 0;
	}
	if(a==0||b==0)
	{
		printf("2");
		return 0;
	}
	if(a<b)
	{
		swap(a,b);
	}
	GCD(a,b);
	printf("%lld",cnt+1);
	return 0;
}
