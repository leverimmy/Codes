#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=1e6+5;
int t,n,c[maxn],d[maxn];
char s[maxn],a[maxn];
signed main()
{
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int ans1=0,ans2=0;
		scanf("%s",s);
		n=strlen(s);
		for(rgi i=1;i<=n;++i)
			a[i]=s[i-1];
		c[0]=0,d[n+1]=0;
		for(rgi i=1;i<=n;++i)
			if(a[i]=='B')
				c[i]=c[i-1]+1;
			else
				c[i]=c[i-1];
		for(rgi i=n;i;--i)
			if(a[i]=='B')
				d[i]=d[i+1]+1;
			else
				d[i]=d[i+1];
		for(rgi i=1;i<=n;++i)
			if(a[i]=='R')
				ans1+=min(c[i],d[i]);
		c[0]=0,d[n+1]=0;
		for(rgi i=1;i<=n;++i)
			if(a[i]=='R')
				c[i]=c[i-1]+1;
			else
				c[i]=c[i-1];
		for(rgi i=n;i;--i)
			if(a[i]=='R')
				d[i]=d[i+1]+1;
			else
				d[i]=d[i+1];
		for(rgi i=1;i<=n;++i)
			if(a[i]=='B')
				ans2+=min(c[i],d[i]);
		printf("%d\n",min(ans1,ans2)); 
	}
	return 0;
}
