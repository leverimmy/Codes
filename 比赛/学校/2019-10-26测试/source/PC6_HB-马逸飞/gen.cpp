#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#define rgi register int
using namespace std;
const int n=1001;
int main()
{
	freopen("light.in","w",stdout);
	srand((unsigned)time(NULL));
	puts("1001 1001");
	for(rgi i=1;i<=n;++i)
	{
		int x=rand()%10000+1;
		cout<<x<<" ";
	}
	putchar('\n');
	int p=(long long)rand()*(long long)rand()%100000000+1;
	for(rgi i=1;i<=n;++i)
	{
		int l=rand()%n+1;
		int r=rand()%n+1;
		if(l>r)
			swap(l,r);
		int q=rand()%min(10000,p)+1;
		cout<<l<<" "<<r<<" "<<p<<" "<<q<<endl;
	}
	return 0;
}
