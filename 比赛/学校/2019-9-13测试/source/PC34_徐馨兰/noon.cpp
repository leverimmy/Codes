#include <bits/stdc++.h>
using namespace std;

int n,m;
unsigned long long ans[100010];
double s[100010];
double maxx[100010];

int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		s[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		s[x]=y*1.0/x;
		for(int j=x;j<=n;j++)
		{
			ans[j]=ans[j-1];
			maxx[j]=maxx[j-1];
			if(s[j]>maxx[j])
			{
				ans[j]++;
				maxx[j]=s[j];
			}
		}
		printf("%ulld\n",ans[n]); 
	}
	return 0;
} 
