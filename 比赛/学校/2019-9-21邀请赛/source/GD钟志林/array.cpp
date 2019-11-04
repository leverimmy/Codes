#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[100005],m,k,ans;
long long p;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	  {
	  	scanf("%d%d",&p,&k);
	  	ans=0;
	  	while (p<=n) p=p+a[p]+k,ans++;
	  	printf("%d\n",ans);
	  } 
	return 0;
}
