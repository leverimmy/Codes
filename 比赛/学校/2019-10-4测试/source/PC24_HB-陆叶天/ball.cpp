#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
int n,m,k,now;
long long up,down;
long long miutup()
{
	long long cal=1,cals=1;
	int kk=0; 
	long long ans=1;
	for(int i=now-m+1;i<=now;i++)
	{
		kk++;
		int nos1,nos2;
		nos1=kk;
		nos2=i;
		for(int j=2;j*j<=i;j++)
		{
			if(j<=kk)
			{
				while(1)
				{
					if(kk%j==0 && i%j==0)
					{
						nos1=nos1/j;
						nos2=nos2/j;
					}
					else
					{
						break;
					}
				}
			}
			if(j>nos1 || j>nos2) break;
		}
		cals*=nos1;
		cal*=nos2;
		for(int j=2;j*j<=cal;j++)
		{
			if(j<=cal)
			{
				while(1)
				{
					if(cal%j==0 && cals%j==0)
					{
						cal=cal/j;
						cals=cals/j;
						ans*=j%1000000007;
					}
					else
					{
						break;
					}
				}
			}
			if(j>cal || j>cals) break;
		}
	}
	ans=cal/cals;
	return ans;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	m--;
	now=n-k;
	if(m>now/2)
	{
		m=now-m;
	}
	printf("%d",miutup()%1000000007);
	return 0;
}

