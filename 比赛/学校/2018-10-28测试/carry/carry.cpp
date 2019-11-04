#include <cstdio>

using namespace std;

int n,a[10010],cnt;

int main()
{
	//freopen("carry.in","r",stdin);
	//freopen("carry.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				cnt++;
			}
	printf("%d",cnt);
	return 0;
}