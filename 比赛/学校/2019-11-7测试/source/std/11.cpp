#include <bits/stdc++.h>

using namespace std;

double x;
int ans;

int main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while (scanf("%lf",&x) != EOF)
	{
		if (x == 0.00)
			break;
		double temp = 0.0;
		for (int i = 2;;i++)
		{
			temp += 1.0 / (double)i;
			if (temp >= x)
			{
				ans = i - 1;
				break;
			}
		}
		printf("%d card(s)\n",ans);
	}
	
	return 0;
}
