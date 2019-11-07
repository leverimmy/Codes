#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
int n,ci[maxn];

int main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	scanf("%d",&n);
	int tn = n;
	for (int i = 2; i * i <= tn; i++)
		if (tn % i == 0)
		{
			while (tn % i == 0)
			{
				ci[i]++;
				tn /= i;
			}
		}
	if (tn > 1)
		ci[tn]++;
	bool flag = false;
	printf("%d=",n);
	for (int i = 2; i <= n; i++)
		if (ci[i])
		{
			if (!flag)
			{
				flag = true;
				if (ci[i] == 1)
					printf("%d",i);
				else
					printf("%d^%d",i,ci[i]);
			}
			else
			{
				printf("*");
				if (ci[i] == 1)
					printf("%d",i);
				else
					printf("%d^%d",i,ci[i]);
			}
		}
	
	return 0;
}
