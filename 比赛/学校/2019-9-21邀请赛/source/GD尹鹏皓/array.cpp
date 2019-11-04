#include<stdio.h>
int n,m,a[100005];
long long p,k,t;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	scanf("%d",&m);
	for(register int i=1;i<=m;i++)
		{
			t=0;
			scanf("%lld%lld",&p,&k);
			while(n>=p)
				{
					p+=a[p]+k;
					t++;
				}
			printf("%lld\n",t);
		}
	return 0;
}
