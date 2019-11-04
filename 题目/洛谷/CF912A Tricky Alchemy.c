#include <stdio.h>
#include <stdlib.h>
long long int yellow,blue,sum,huang,lan;
long long int x,y,z;
/*
	yellow是我们已有的黄水晶数量；
    blue是我们已有的蓝水晶数量；
    sum是我们还需的水晶总数；
    huang是我们还需的黄水晶的数量；
    lan是我们还需的蓝水晶的数量；
    x是我们要做的黄水晶球的个数；
    y是我们要做的绿水晶球的个数；
    z是我们要做的蓝水晶球的个数。
    
    这一题的数据是0~10^9
	所以我们应该开大一点，用long long
*/

int main()
{

    scanf("%lld %lld",&yellow,&blue);
    scanf("%lld %lld %lld",&x,&y,&z);//既然用了long long，就用%lld
	huang=2*x+y;//计算我们还需要多少黄水晶
    lan=3*z+y;//计算我们还需要多少蓝水晶
    if(huang>yellow)//如果需要的大于我们已有的
		sum=sum+huang-yellow;//把差的加进sum里面
    if(lan>blue)
		sum=sum+lan-blue;//同理
    printf("%lld",sum);//输出
	system("pause");
	return 0;
}
