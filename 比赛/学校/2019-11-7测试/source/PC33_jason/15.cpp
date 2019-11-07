#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int a[100001];
signed main()
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	int n,mx=0,at=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>mx)
			mx=a[i],at=i;
	}
	printf("%d %d",mx,at);
	return 0;
}