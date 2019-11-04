#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n,k;
	int sum=0,di=0;//sum是总和，di是暂时烟蒂的数量
	scanf("%d %d",&n,&k);//输入
	sum=sum+n;//第一次总和加上n
	di=n;//第一次烟蒂的数量为n
	while(di>=k)//如果di的数量比k大（也就是还可以做新的烟）
	{
		di=di-k;//烟蒂自己减去k
		di++;//但是新的一根烟又产生了一个新的烟蒂
		sum++;//总数加1
	}
	printf("%d",sum);
	return 0;
}
