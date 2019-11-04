#include <cstdio>

using namespace std;

int n,a[50010];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int ans=0;
		scanf("%d",&a[i]);
		for(int j=0;j<=i;j++)
			if((i&j)==j)
				ans+=a[j];
		printf("%d\n",ans);
	}
	return 0;
}