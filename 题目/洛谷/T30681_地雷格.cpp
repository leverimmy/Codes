#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m;
char map[110][110];
int i,j;
int main()
{
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map[i][j]=='*')
				printf("*");
			else
			{
				int t=0;
				if(map[i][j-1]=='*')
					t++;
				if(map[i][j+1]=='*')
					t++;
				if(map[i-1][j]=='*')
					t++;
				if(map[i+1][j]=='*')
					t++;
				if(map[i+1][j+1]=='*')
					t++;
				if(map[i+1][j-1]=='*')
					t++;
				if(map[i-1][j+1]=='*')
					t++;
				if(map[i-1][j-1]=='*')
					t++;
				printf("%d",t);
				t=0;
			}
		}
		printf("\n");
	}
	return 0;
}