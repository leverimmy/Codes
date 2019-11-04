#include <cstdio>
#include <algorithm>

using namespace std;

int n,sum,ave,cnt;
int a[110];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=sum/n;
	for(int i=1;i<=n;i++)
		if(a[i]!=ave)
		{
			a[i+1]=a[i+1]+a[i]-ave;
			cnt++;
		}
	printf("%d",cnt);
	return 0;
}