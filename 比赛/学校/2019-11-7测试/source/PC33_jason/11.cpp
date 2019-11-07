#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const double eps=1e-6;
signed main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(1)
	{
		double n;
		cin>>n;
		if(n<eps)
			return 0;
		int j=1;
		double ans=0;
		while(ans+eps<n)
			ans+=(double)1/(++j);
		printf("%d card(s)\n",j-1);
	}
	return 0;
}