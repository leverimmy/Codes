#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int t;

int is_prime(int n)//这里是判断质数的函数
{
	if(n<2)
		return 0;//小于2的整数都不是质数
	else
		for(int i=2;i*i<=n;i++)//从2开始循环，直至sqrt(n)
			if(n%i==0)//如果中间有数可以整除
				return 0;//那它就不是质数
	return 1;//否则就是质数
}

int main()
{
	scanf("%d",&t);//t是总和
	for(int i=2;i<=t;i++)//从2开始，一直到t
		if(is_prime(i)==1)//如果i还是个质数
			for(int j=i;j<=t;j++)//从k开始，一直到t
				if(is_prime(j)==1)//如果j还是个质数
				{
					if(is_prime(t-i-j)==1)//如果剩下的那个数还是质数
					{
						printf("%d %d %d",i,j,t-i-j);//输出第一组
						return 0;//为了避免输出后面的，我们就return 0；
					}
				}
}