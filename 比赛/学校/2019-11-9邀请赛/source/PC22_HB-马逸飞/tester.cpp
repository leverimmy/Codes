#include <cstdio>
#include <cstdlib>
#include <ctime>
signed main()
{
	system("tree.exe");
	int t=clock();
	if(system("fc tree.out tree.ans"))
		printf("WA time=%dms",t);
	else
		printf("AC time=%dms",t);
	return 0;
}
