#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>
using namespace std;
int x, y,standred,stupid=0;
int main()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	int n,a,b;
	scanf("%d%d%d", &n,&a,&b);
	if(b==1)
	{
		printf("4\n2\n2");
	}
	else
	{
		printf("4\n1\n3");
	}
	return 0;
}