#include <cstdio>

using namespace std;

int n,m,r,q;

int main()
{
	scanf("%d %d",&n,&m);
	q=n/m;
	r=n%m;
	for(int i=r;i<m;i++)
		printf("%d ",q);
	for(int i=0;i<r;i++)
		printf("%d ",q+1);
	return 0;
}