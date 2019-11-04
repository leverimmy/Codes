#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
int p,k;
int ans;
int a[100005];
int s[100005][305];

int main()
{
	freopen("array.in","r",stdin); 
	freopen("array.out","w",stdout); 
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(int i=n;i>=1;i--)
	for(int j=0;j<=300;j++)
	{
		if(a[i]+i+j>n)s[i][j]=1;
		else s[i][j]=s[a[i]+i+j][j]+1;
	}
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&k);
		if(k<=300)
		{
			printf("%d\n",s[p][k]);
		}
		else
		{
			ans=0;
			while(p<=n)
			{
				ans++;
				p+=a[p]+k;
			}
			printf("%d\n",ans);
		}
	}
	
	
	return 0;
}
