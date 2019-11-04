#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int c=100000010;
int n;
int b;
int a[c];
int d[301][200000];
int minn=100000000,maxn=0;
int s=1;
int mj(int i,int j)
{
	if(i==n+1)
	{
		s++;
		int k;
		for(k=1;k<=n;k++)
			d[s][k]=d[s-1][k];
		return 1;
	}
	if(i==1)
	{
		int k;
		for(k=minn/2;k>=1;k--)
		{
			d[s][1]=k;
			mj(i+1,k);
			d[s][1]=0;
		}
	}
	else
	{
		int k,x,y;
		for(k=j;k<=maxn;k++)
		{
			y=0;
			for(x=1;x<i;x++)
			{
				if(a[d[s][x]+k]==0)
				{
					y=1;
					break;
				}
			}
			if(y==1)
				continue;
			else
			{
				d[s][i]=k;
				for(x=1;x<i;x++)
					a[d[s][x]+k]--;
				mj(i+1,k);
				d[s][i]=0;
				for(x=1;x<i;x++)
					a[d[s][x]+k]++;
			}
		}
		return 1;
	}
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	memset(a,0,c-1);
	cin>>n;
	for(b=n*(n-1)/2;b>=1;b--)
	{
		int x;
		cin>>x;
		a[x]++;
		minn=min(minn,x);
		maxn=max(maxn,x);
	}
	mj(1,1);
	cout<<s-1<<endl;
	for(b=1;b<s;b++)
	{
		for(int e=1;e<=n;e++)
			cout<<d[b][e]<<" ";
		cout<<endl;
	}
	return 0;
}
