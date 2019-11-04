#include <cstdio>
#define ll long long
using namespace std;

ll k,m,n,flag;
ll pow,atk;

int main()
{
	scanf("%lld %lld %lld",&k,&m,&n);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld %lld",&pow,&atk);
		if(pow==0 && atk>0)
		{
			flag=1;
			printf("%lld ",i);
		}
		else if(k/pow*atk>=n)
		{
			flag=1;
			printf("%lld ",i);
		}
	}
	if(flag==0)
		printf("-1");
	return 0;
}