#include <cstdio>
#include <algorithm>

using namespace std;

int n,sum,maxn=-99999,minn;
int a[200010],p[200010],s[200010];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	p[1]=a[1];
	minn=min(0,s[1]);
	for(int i=2;i<=n;i++)
	{
		p[i]=s[i]-minn;
		minn=min(minn,s[i]);
	}
	for(int i=1;i<=n;i++)
		maxn=max(maxn,p[i]);
	printf("%d",maxn);
	return 0;
}