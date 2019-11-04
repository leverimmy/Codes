#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,s,a,b;
int x[5100];
int y[5100];
int h,t,cnt;

int main()
{
	scanf("%d %d",&n,&s);
	scanf("%d %d",&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&x[i],&y[i]);
	h=a+b;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if(y[j]>y[j+1])
			{
				t=y[j];
				y[j]=y[j+1];
				y[j+1]=t;
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
	//for(int i=1;i<=n;i++)
	//	printf("%d %d\n",x[i],y[i]);
	for(int i=1;i<=n;i++)
		if(s-y[i]>=0 && h>=x[i])
		{
			cnt++;
			s=s-y[i];
		}
	printf("%d",cnt);
	return 0;
}