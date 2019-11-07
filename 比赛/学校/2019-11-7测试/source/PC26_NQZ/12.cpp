#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	int x;
	int ans=0;
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

