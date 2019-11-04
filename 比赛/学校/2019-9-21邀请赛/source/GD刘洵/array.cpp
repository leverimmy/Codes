#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
long long ans,t;
int n,m,a[100005],x,y,p,k;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	 } 
	 cin>>m;
	 for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&k);
		t=p+k+a[p];
		ans=n/t+1;
		printf("%lld\n",ans);
	}
	
} 
