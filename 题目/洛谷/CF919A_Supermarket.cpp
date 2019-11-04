#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m;
int a,b;
double t=111111;
	
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		t=min(t,(double)a/b);
	}
	printf("%.8lf",t*m);
	return 0;
}