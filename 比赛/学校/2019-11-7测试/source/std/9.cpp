#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
int limit,n,r,ans[maxn],top;

int main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	scanf("%d,%d,%d",&limit,&n,&r);
	for (int i = r; i <= limit; i += n)
	{
		if (i == 0)
			continue;
		ans[++top] = i;
	}
	for (int i = 1; i <= top; i++)
	{
		if (i % 10 == 0 || i == top)
			printf("%d\n",ans[i]);
		else
			printf("%d,",ans[i]);
	}
	
	return 0;
}
