#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,k;
int t,cnt;
double sum;

int round_double(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5); 
}//我们自己设置一个round_double()函数，它可以帮助我们四舍五入

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		sum=sum+t;//先把总和算出来
	}
	while(round(sum/(cnt+n))!=k)//如果四舍五入后还不到k
	{
		sum+=k;
		cnt++;//我们就继续
	}
	printf("%d",cnt);
	return 0;
}