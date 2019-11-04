#include <cstdio>

long long s;

int is_prime(long long num)
{
	if(num<2)
		return 0;
	for(long long i=2;i*i<=num;i++)
		if(num%i==0)
			return 0;
	return 1;
}

bool is_two(long long n)
{
	return n > 0 ? (n & (n - 1)) == 0 : false;
}

int main()
{
	scanf("%lld",&s);
	if(is_prime(s)==1)
	{
		printf("%lld ",s/2);printf("%lld",s/2+1);
	}
	else if(is_two(s))
	{
		printf("%lld ",s);printf("%lld",s);
	}
	else
	{
		for(long long begin=1;begin<=s;begin++)
		{
			for(long long last=begin;last<=s;last++)
				if((begin+last)*(last-begin+1)/2==s)
				{
					printf("%lld %lld",begin,last);
				}
		}
	}
	return 0;
}