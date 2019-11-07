#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
signed main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%d=",n);
	bool flg(0);
	for(int i=2;i<=n;i++)
	{
		int p(0);
		while(!(n%i))
		{
			n/=i;
			p++;
		}
		if(p)
		{
			if(flg)
				printf("*");
			if(!flg)
				flg=1;
			printf("%d",i);
			if(p>1)
				printf("^%d",p);
		}
	}
	return puts(""),0;
}
