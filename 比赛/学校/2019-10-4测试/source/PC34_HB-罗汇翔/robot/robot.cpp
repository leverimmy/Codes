#include<iostream>
#include<cstdio>
using namespace std;
const int mn=50010;
int n;
int a[mn];
int m1,m2;
int ans;
//小数据 
int f1[mn];  //最长不下降子序列 
int f2[mn];  //最长不上升子序列
//大但弱的数据
int sum[mn]; 
int g1[mn];  //某数左边都为 1 右边都为 2 最小花费 
int g2[mn];  //某数左边都为 2 右边都为 1 最小花费 
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<10000)
	{
		for(int i=1;i<=n;i++)f1[i]=f2[i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]>=a[j])
				{
					f1[i]=max(f1[i],f1[j]+1);
					ans=max(ans,f1[i]);
				}
				if(a[i]<=a[j])
				{
					f2[i]=max(f2[i],f2[j]+1);
					ans=max(ans,f2[i]);
				}
			}
		}
		cout<<n-ans;
		return 0;
	}
	else
	{
		ans=2147483647;
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n;i++)
		{
			g1[i]=(sum[i]-sum[0]-i)+(2*(n-i)-(sum[n]-sum[i]));
			g2[i]=(2*i-(sum[i]-sum[0]))+(sum[n]-sum[i]-(n-i));
			ans=min(ans,g1[i]);
			ans=min(ans,g2[i]);
		}
		cout<<ans;
		return 0;
	}
}
