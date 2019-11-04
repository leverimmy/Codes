#include<bits/stdc++.h>
using namespace std;
int n,f;
int a[100020];
int p[100020];
int sum[100020];
int ans =0;
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	scanf("%d%d",&n,&f);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	/*for(int i=1;i<=n;i++)
	   for(int len=1;i+len*2+f-1<=n;len++)  
		{
			bool bo =0;
			for(int k=0;k<len;k++)
			  if(a[i+k]!=a[i+len+f+k]) 
			  {
			  	bo=true;
			  	break;
			  }
			if(!bo) ans ++;
		}*/
	for(int len=1;len*2+f<=n;len++)
	{
		memset(p,0,sizeof(p));
		memset(sum,0,sizeof(sum));
		for(int i=len+f+1;i<=n;i++)
		  if(a[i] == a[i-len-f]) p[i] = 1;
		  else p[i] = 0;
		for(int i=1;i<=n;i++) sum[i] = sum[i-1] + p[i];
		for(int i=len+f+1;i<=n;i++)  if(sum[i] - sum[i-len] == len)
		  ans++;
	}
	printf("%d\n",ans);
	return 0;
}
