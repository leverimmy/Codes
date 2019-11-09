#include <cstdio>
#include <cstdlib>
using namespace std;
int n,a[200005],pre[200005],suf[200005],maxpre[200005],maxsuf[200005];
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	pre[0]=suf[n-1]=maxpre[0]=maxsuf[n-1]=1;
	for(int i=1;i<n;i++) pre[i]=a[i]>a[i-1]?(pre[i-1]+1):1;
	for(int i=n-2;i>=0;i--) suf[i]=a[i]<a[i+1]?(suf[i+1]+1):1;
	int ans=0;
	for(int i=0;i<n;i++) 
	{
		int maxc=0;
		if(ans<pre[i]+suf[i]-1) ans=pre[i]+suf[i]-1;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>=a[i]&&suf[j]>maxc) maxc=suf[j];
		}
		if(ans<pre[i]+maxc) ans=pre[i]+maxc;
	}
	printf("%d",ans);
	//system("pause");
	return 0;
}
