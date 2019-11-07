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
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(n%i==0)
			ans++;
	printf("%d",ans);
	return 0;
}