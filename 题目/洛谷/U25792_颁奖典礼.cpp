#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int x,y;
int a[1100];
int b[1100];
int g[1100];
int k[1100];
int map[1100][1100];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d %d",&a[i],&b[i],&g[i],&k[i]);
	scanf("%d %d",&x,&y);
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=a[i]+g[i];j++)
			for(int t=b[i];t<=b[i]+k[i];t++)
				map[j][t]=i;
	if(map[x][y]==0)
		printf("-1");
	else
		printf("%d",map[x][y]);
	return 0;
}