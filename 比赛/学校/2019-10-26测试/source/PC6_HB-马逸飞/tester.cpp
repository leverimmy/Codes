#include <cstdio>
#include <cstdlib>
#include <ctime>
signed main()
{
	while(1)
	{
		system("gen.exe");
		system("std.exe");
		int s=clock();
		system("light.exe");
		int t=clock();
		if(system("fc light.out light.ans"))
		{
			printf("WA time=%dms",t-s);
			break;
		}
		else
			printf("AC time=%dms",t-s);
	}
	return 0;
}
