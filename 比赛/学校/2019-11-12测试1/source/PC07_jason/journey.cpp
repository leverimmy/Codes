#include<bits/stdc++.h>
using namespace std;
int num[100001],u[100001],v[100001],val[100001];
int a[100001],b[100001],kmp[100001];
signed main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d%d",&num[i],&u[i],&v[i],&val[i]);
		int cnt=0;
		a[++cnt]=u[1];
		for(int i=1;i<=m;i++)
			a[++cnt]=v[i];
		int len;
		scanf("%d",&len);
		for(int i=1;i<=len;i++)
			scanf("%d",&b[i]);
		long long maxt;
		scanf("%lld",&maxt);
		kmp[1]=0;
		for(int i=2;i<=len;i++)
		{
			int k=kmp[i-1];
			while(k&&b[k+1]!=b[i])
				k=kmp[i];
			if(b[k+1]==b[i])
				k++;
			kmp[i]=k;
		}
		int k=0,flag=0;
		long long ans=0;
		for(int i=1;i<=cnt;i++)
		{
			while(k&&b[k+1]!=a[i])
				k=kmp[k];
			if(b[k+1]==a[i])
				k++;
			ans+=val[i-1];
			if(k==len)
			{
				if(ans<=maxt) 
				{
					flag=1;
					printf("YES %lld\n",ans);
				}
				break;
			}
		}
		if(!flag)
			printf("NO\n");
	}
	return 0;
}
