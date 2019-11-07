#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

signed main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	int a,b,c;
	cin>>a;
	cin>>b;
	int las=0;
	
	int flag=0;
	for(int i=a;i+4<=b;i+=5)
	{
		if(flag==0)
		for(int j=0;j<=4;j++)
			printf("%d ",i+j);
		else
		for(int j=4;j>=0;j--)
			printf("%d ",i+j);
		flag^=1;
		printf("\n");
		las=i+5;
	}
	if(flag==0)
	for(int i=las;i<=b;i++)
		printf("%d ",i);
	else
	for(int i=b;i>=las;i--)
		printf("%d ",i);
	return 0;
}