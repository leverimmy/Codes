#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int flag;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(i*i*i==n)
			flag=1;
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}