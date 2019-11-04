#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,cnt,yest;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);//输入今天的上课时间
		yest+=a+b-8;//把不高兴值加起来
		cnt+=yest;//累计起来
	}
	printf("%d",cnt);
	return 0;
}