#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int ans,m,n;
int a[110];
void dfs(int from,int sum)
{
	if(sum==m)
		ans++;
	else
		for(int i=from;i<n;i++)
			if(sum+a[i]<=m)
				dfs(i+1,sum+a[i]);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int j=0;j<n;j++)
		scanf("%d",&a[j]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}