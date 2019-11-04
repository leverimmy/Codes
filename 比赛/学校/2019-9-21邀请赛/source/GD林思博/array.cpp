#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,a[10005],p,k;
long long s;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&k);
		s=0;
		while(p<=n)
		{
			p=p+a[p]+k;
			s++;
		}
		printf("%lld\n",s);
	}
}
