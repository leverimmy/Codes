#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int map[1100][1100];
int flag=0;
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==1)
				flag=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]==0)
			{
				
			}
}