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

int n,m;

int is_prime(int x)
{
	if(x<2)
		return 0;
	else
		for(int i=2;i*i<=x;i++)
			if(x%i==0)
				return 0;
	return 1;
}

int main()
{
	scanf("%d %d",&n,&m);
	while(m--)
	{
		int p;
		scanf("%d",&p);
		if(is_prime(p)==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}