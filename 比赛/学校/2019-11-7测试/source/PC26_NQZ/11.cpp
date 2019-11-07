#include <bits/stdc++.h>
using namespace std;
double x;
int main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(1)
	{
		scanf("%lf",&x);
		if(x==0.00)
		{
			return 0;
		}
		int ans=0;
		double now=0.00;
		for(double i=2.00;;i++)
		{
			ans++;
			now+=1.00/i;
			if(now>=x)
			{
				break;
			}
		}
		printf("%d card(s)\n",ans);
	}
	return 0;
}

