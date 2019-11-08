#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int a[MAXN];
int main()
{
	freopen("4.in","w",stdin);
	freopen("4.out","r",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=N;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

