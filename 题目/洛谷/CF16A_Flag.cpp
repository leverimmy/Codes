#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

int n,m,flag=11111111;
char s[105][105];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			if(s[i][j]!=s[i][0])
			{
				flag=0;
				break;
			}
	if(flag==0)
	{
		printf("NO");
		return 0;
	}
	for(int i=2;i<=n;i++)		
			if(s[i][0]==s[i-1][0])
			{
				flag=0;
				break;
			}
		}
    if(flag)
		printf("YES");
    else
		printf("NO");
	return 0;
}
