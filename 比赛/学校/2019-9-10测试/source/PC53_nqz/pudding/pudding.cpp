#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=5005;
int col[MAXN];
int main()
{
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",col+i);
	}
	for(int p=1;p<=M;p++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			for(int i=1;i<=N;i++)
			{
				if(col[i]==a)
				{
					col[i]=b;
				}
			}
		}
		else
		{
			int now=0;
			for(int i=1;i<=N;i++)
			{
				if(col[i]!=col[i-1])
				{
					now++;
				}
			}
			printf("%d\n",now);
		}
	}
	return 0;
}
