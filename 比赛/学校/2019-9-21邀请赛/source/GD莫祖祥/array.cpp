#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,ans,x,y,a[100005],f[100005],g[100005];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
	 if (a[i]+i>n) f[i]=1;
	  else f[i]=f[a[i]+i]+1;
	  
	/*for (int i=n;i>=1;i--)
	 if (a[i]+i+1>n) g[i]=1;
	  else g[i]=g[a[i]+i+1]+1;*/
	cin>>m;
	if (n<=100)
	 {
	 	for (int i=1;i<=m;i++)
	 	 {
	 	 	scanf("%d%d",&x,&y);
	 	 	ans=0;
	 	 	while (x<=n) 
	 	 	 {
	 	 	 	++ans;
	 	 	 	x=x+a[x]+y;
	 	 	 }
	 	 	printf("%d\n",ans);
	 	 }
	 }
	else
	{
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d",&x,&y);
	 	if (y==0) printf("%d\n",f[x]); 
	 	else
	 	 {
	 	 	ans=0;
	 	 	while (x<=n) 
	 	 	 {
	 	 	 	++ans;
	 	 	 	x=x+a[x]+y;
	 	 	 }
	 	 	printf("%d\n",ans);
	 	 }
	}
}
	return 0;
}
