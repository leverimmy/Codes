#include <cstdio>
#include <algorithm>

using namespace std;

int n,b,sum,cnt;
int h[20010];

int main()
{
	scanf("%d %d",&n,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	sort(h+1,h+n+1);
	/*for(int i=1;i<=n;i++)
		printf("%d ",h[i]);*/
	for(int i=n;i>=1;i--)
		if(sum<b)
		{
			sum+=h[i];
			cnt++;
		}
	printf("%d",cnt);
	return 0;
}