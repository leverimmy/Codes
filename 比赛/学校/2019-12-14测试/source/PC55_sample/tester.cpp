#include <bits/stdc++.h>
using namespace std;
signed main()
{
	system("game.exe");
	int t=clock();
	if(system("fc game.out game.ans"))
		printf("WA time=%dms\n",t);
	else
		printf("AC time=%dms\n",t);
	return 0;
}
