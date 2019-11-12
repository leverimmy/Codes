#include <cstdio>
#include <cstdlib>
#include <ctime>
signed main()
{
	system("matrix.exe");
	int t=clock();
	if(system("fc matrix.out matrix.ans"))
		printf("WA time=%dms",t);
	else
		printf("AC time=%dms",t);
	return 0;
}
