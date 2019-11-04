#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int flag,cnt;
int book[10];
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	for(int A=123;A<=333;A++)//由于A<B<C，所以我们只用从123循环到333
	{
		flag=1;//假设此时成立
		int B=b*A/a;
		int C=c*A/a;//用比例算出B和C的值
		int abai,ashi,age,bbai,bshi,bge,cbai,cshi,cge;//这分别是A，B，C的百、十、个位
		abai=A/100;ashi=A/10%10;age=A%10;
		bbai=B/100;bshi=B/10%10;bge=B%10;
		cbai=C/100;cshi=C/10%10;cge=C%10;
		book[abai]++;book[ashi]++;book[age]++;
		book[bbai]++;book[bshi]++;book[bge]++;
		book[cbai]++;book[cshi]++;book[cge]++;//我们用类似于桶排序的想法进行去重，只用看去重完后的个数是否为9即可
		for(int i=1;i<=9;i++)
			if(book[i]!=1)//如果1~9中有个数没有出现，即其他数字中有个数出现了两次
				flag=0;//排除掉这种情况
		if(flag==1)
		{
			printf("%d %d %d\n",A,B,C);
			cnt++;//如果可以的话就输出
		}
		for(int i=1;i<=9;i++)
			book[i]=0;
	}
	if(cnt==0)
		printf("No!!!");//如果一种可能都没有，那就输出No!!!
	return 0;
}