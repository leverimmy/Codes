#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int num[1000010],n,k;

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
		num[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i && j<=k;j++)
			num[i]=(num[i]+num[i-j])%100003;
	printf("%d",num[n]);
	return 0;
}