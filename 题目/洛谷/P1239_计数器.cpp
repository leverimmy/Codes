#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int digit[10];
int n,x;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		x=i;
		while(x)
		{
			digit[x%10]++;
			x=x/10;
		}
	}
	for(int i=0;i<=9;i++)
		printf("%d\n",digit[i]);
	return 0;
}