#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	system("gfw.exe");
	int t=clock();
	if(system("fc gfw.out gfw.ans"))
		printf("WA time=%dms",t);
	else
		printf("AC time=%dms",t);
	return 0;
}
