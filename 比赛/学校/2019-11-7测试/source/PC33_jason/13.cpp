#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const double eps=1e-6;
int cnt[1000001];
signed main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	int n,m,ans=0;
	cin>>n;
	m=n;
	printf("%d=",n);
	for(int i=2;i<=sqrt(n);i++)
	{
		while(n%i==0)
			cnt[i]++,n/=i;
	}
	int las=0;
	for(int i=2;i<=sqrt(m);i++)
		if(cnt[i])
		{
			if(las)
			{
				if(cnt[i]==1)
					printf("*%d",i);
				else
					printf("*%d^%d",i,cnt[i]);
			}
			else
			{
				if(cnt[i]==1)
					printf("%d",i);
				else
					printf("%d^%d",i,cnt[i]);
				las=1;
			}
		}
	if(n!=1)
	{
		if(las)
			printf("*%d",n);
		else
			printf("%d",n);
	}
	return 0;
}