#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,k,a[100],ans;
int prime(int r)//质数判断函数
{
	if(r<2)
		return 0;
	for(int t=2;t*t<=r;t++)
		if(r%t==0)
			return 0;
	return 1;
}
void dfs(int x,int y,int z)//x是当前在第几个数；y是已经填写了几个数；z是之前的填写的数的和
{
	if(x>n)//如果已经填写完了
	{
		if(y==k)//如果刚好也填写了k个数
			ans+=prime(z);//那么就累加
/*
	这一步操作值得人玩味
	prime(z)只会返回0和1两个值
	如果是质数，那就ans++；
	如果不是，那就不做操作
	而这个ans+=prime(z)；
	最为简洁
*/
		return;//返回
	}
	dfs(x+1,y+1,z+a[x]);//考虑填写了第x个数后的操作
	dfs(x+1,y,z);//考虑没有填写第x个数后的操作
}
int main()
{
	scanf("%d %d",&n,&k);//先输入n和k
	for(int j=1;j<=n;j++)
		scanf("%d",&a[j]);//输入备选的数
	dfs(1,0,0);//dfs
	printf("%d",ans);//输出答案
	return 0;
}