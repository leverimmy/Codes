#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int a[maxn][maxn],num[maxn],L,R,p;

int main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	scanf("%d%d",&L,&R);
	p = 1;
	for (int i = L; i <= R; i++)
	{
		++num[p];
		a[p][num[p]] = i;
		if (num[p] % 5 == 0)
			p++;
	}
	if (num[p] == 0)
		p--;
	for (int i = 2; i <= p; i += 2)
		reverse(a[i] + 1,a[i] + 1 + num[i]);
	for (int i = 1; i <= p; i++)
	{
		for (int j = 1; j <= num[i]; j++)
		{
			if (j == num[i])
				printf("%d",a[i][j]);
			else
				printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
