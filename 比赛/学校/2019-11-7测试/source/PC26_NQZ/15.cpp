#include <bits/stdc++.h>
using namespace std;
int a[100005],maxx,pos;
int main()
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int now;
		scanf("%d",&now);
		if(now>maxx)
		{
			maxx=now;
			pos=i;
		}
	}
	printf("%d %d",maxx,pos);
	return 0;
}

