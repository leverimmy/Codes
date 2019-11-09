#include <cstdio>
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	int n,ans=0;
	int a[1001];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n-i+1;j++)
		{
			int ls=0;
			int rec=-1;
			int res=0;
			for(register int k=1;k<=n;k++)
			{
				rec=a[k];
				for(register int l=k+1;l<=n;l++)
				{
					if(l>j && l<i+j-1)
						continue;
					if(a[l]>rec)
						res++;
					else
					{
						ls=res;
						res=0;
						break;
					}
					rec=a[l];
				}
			}
			ans=max(ans,ls);
		}
	}
	cout<<ans;
}
/*
9
5 3 4 9 2 8 6 7 1
*/