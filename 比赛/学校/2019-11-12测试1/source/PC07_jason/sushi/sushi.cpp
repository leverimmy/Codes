#include<bits/stdc++.h>
using namespace std;
#define int long long
char str[2000001];
int a[2000001];
signed main()
{
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		cin>>str+1;
		int n=strlen(str+1);
		long long suml=0,sumr=0,cntl=0,cntr=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='R') 
				a[i]=1;
			else 
				a[i]=0;
			if(i<=n/2) 
				suml+=a[i]*i,cntl+=a[i];
			else 
				sumr+=a[i]*i,cntr+=a[i];
		}
		for(int i=1;i<=n;i++)
			a[i+n]=a[i];
		long long ans=(long long)1e18;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,suml-(1+cntl)*cntl/2+(n+n-cntr+1)*cntr/2-sumr);
	/*		if(i)
			{
				long long tsuml=0,tcntl=0,tsumr=0,tcntr=0;
				for(int j=i;j<i+n/2;j++)
					tsuml+=a[j]*(j-i+1),tcntl+=a[j];
				for(int j=i+n/2;j<=i+n-1;j++)
					tsumr+=a[j]*(j-i+1),tcntr+=a[j];
			//	if(tsuml!=suml||tcntl!=cntl||tsumr!=sumr||tcntr!=cntr)
			//		printf("!");
			ans=min(ans,tsuml-(1+tcntl)*tcntl/2+(n+n-tcntr+1)*tcntr/2-tsumr);
			if(tsuml-(1+tcntl)*tcntl/2+(n+n-tcntr+1)*tcntr/2-tsumr==0)
				printf("!");
			}*/
			suml-=cntl,sumr-=cntr;
			if(a[i])
			{
				cntl--;
				sumr+=n;
				cntr++;
			}
			if(a[i+n/2])
			{
				suml+=n/2;
				cntl++;
				sumr-=n/2;
				cntr--;
			}
				
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
BBBBRRRBRBRBRBRBRBR


1
BBAAB ABABAB
*/