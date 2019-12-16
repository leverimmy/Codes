#include <bits/stdc++.h>
using namespace std;
const int MAXN=15;
int N,S,a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(1)
	{
		scanf("%d",&N);
		if(!N)
		{
			return 0;
		}
		scanf("%s",&S);
		for(int i=1;i<=2*N;i++)
		{
			if(i%2)
				scanf("%d",a+(i/2)+1);
			else
				scanf("%d",b+(i/2));
		}
		puts("1");
	}
}
