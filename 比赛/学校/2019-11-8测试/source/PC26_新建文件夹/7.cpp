#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int now;
int isprime[MAXN],prime[MAXN];
void Euler(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(!isprime[i])
		{
			now++;
			prime[now]=i;
		}
		for(int j=1;j<=now&&prime[j]*i<=x;j++)
		{
			isprime[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
}
int main()
{
	freopen("7.in","w",stdin);
	freopen("7.out","r",stdout);
	int N;
	scanf("%d",&N);
	Euler(N);
	for(int i=1;i<=now;i++)
	{
		printf("%d ",prime[i]);
	}
	return 0;
}

