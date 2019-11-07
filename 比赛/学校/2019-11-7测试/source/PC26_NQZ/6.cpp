#include <bits/stdc++.h>
using namespace std;
int len,now;
int a[1<<26+2];
int main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		a[len+1]='A'+i-1;
		for(int j=1;j<=len;j++)
		{
			a[len+j+1]=a[j];
		}
		len+=len;
		len++;
	}
	for(int i=1;i<=len;i++)
	{
		printf("%c",a[i]);
	}
	putchar('\n');
	return 0;
}
