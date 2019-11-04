#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

double t;
int a,n;
int fenzi,fenmu;
int m;

int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&n);
		t=sqrt(2*n+0.25);
		a=ceil(t-0.5);
		if(a%2==0)
		{
			fenzi=a-a*(a+1)/2+n;
			fenmu=1+a*(a+1)/2-n;
		}
		else
		{
			fenmu=a-a*(a+1)/2+n;
			fenzi=1+a*(a+1)/2-n;
		}
		printf("TERM %d IS %d/%d\n",n,fenzi,fenmu);
	}
	return 0;
}