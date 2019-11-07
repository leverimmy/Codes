#include <bits/stdc++.h>
using namespace std;
int prime[100009],num[199999];
int now;
int main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	int N;
	int o;
	scanf("%d",&N);
	o=N;
	for(int i=2;i*i<=N;i++)
	{
		if(N%i==0)
		{
			now++;
			prime[now]=i;
			while(N%i==0)
			{
				N/=i;
				num[now]++;
			}
		}
	}
	if(N!=1)
	{
		now++;
		prime[now]=N;
		num[now]=1;
	}
	printf("%d=",o);
	for(int i=1;i<now;i++)
	{
		printf("%d",prime[i]);
		if(num[i]!=1)
		{
			printf("^%d",num[i]);
		}
		printf("*");
	}
	printf("%d",prime[now]);
	if(num[now]!=1)
	{
		printf("^%d",num[now]);
	}
	return 0;
}

