#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int i;
	for(i=100;i<=999;i++)
	{
		int bai=i/100;
		int shi=i%100/10;
		int ge=i%10;
		if(bai*bai*bai+shi*shi*shi+ge*ge*ge==i)
			printf("%d\n",i);
	}
	return 0;
}