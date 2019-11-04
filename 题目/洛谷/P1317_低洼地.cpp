#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,j;
int a[10100],b[10100];
int cnt;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);//输入
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])
		{
			j++;
			b[j]=a[i];//去重后放入b数组
		}
	for(int i=2;i<=j-1;i++)
		if(b[i]<b[i-1] && b[i]<b[i+1])//如果b[i]左右都比它高，那么它一定会积水
			cnt++;
	printf("%d",cnt);
	return 0;
}