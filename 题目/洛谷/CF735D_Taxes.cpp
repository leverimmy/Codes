#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;

int is_prime(int num)
{
	if(num < 2)
		return 0;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0)
			return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	if(is_prime(n))
		cout << 1; //如果是质数就分为1份
	else if(n % 2 == 0)
		cout << 2; //如果n是偶数，由哥德巴赫猜想可知，n可以分为两个质数的和
	else if(n % 2 == 1)
	{
		if(is_prime(n - 2))
			cout << 2;//如果n-2是质数，n就可以分为n-2和2，分成2份
		else
			cout << 3;//如果n是奇数且n-2不是质数，就只能分为3和n-3
					  //注意这里3是质数，n-3是偶数，所以要分为3份
	}
	return 0;
}

