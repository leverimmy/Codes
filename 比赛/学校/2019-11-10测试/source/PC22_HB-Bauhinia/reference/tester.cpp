#include <bits/stdc++.h>
signed main()
{
	system("reference.exe");
	int t=clock();
	if(system("fc reference.out reference.ans"))
		printf("WA time=%dms",t);
	else
		printf("AC time=%dms",t);
	return 0;
}
