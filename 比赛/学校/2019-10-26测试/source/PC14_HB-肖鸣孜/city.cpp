#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int n,anscnt,sum[305],ans[305],cnt[10000];
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n*(n-1)/2;i++)
	{
		scanf("%d",&sum[i]);
		cnt[sum[i]]++;
	}
	sort(sum,sum+n);
	if(n==1) {printf("1\n%d",sum[0]);return 0;}
	
	return 0;
}
