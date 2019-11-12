#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("boynextdoor.in","r",stdin);
	freopen("boynextdoor.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(!x) printf("%d\n",-y);
		else if(!y) printf("%d\n",x);
		else
		{
			int sec=y+1;
			printf("%d\n",x+y-sec*2);
		}
	}
	return 0;
};