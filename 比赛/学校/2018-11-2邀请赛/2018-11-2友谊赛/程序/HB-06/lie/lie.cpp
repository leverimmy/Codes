#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int l,r,num;
}a[100001],s[100001];
int dp[100001];
bool cmp(node a,node b)
{
	if(a.r!=b.r)
		return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	int n,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		if(q+p<=n-1)
			a[++num].l=p+1,a[num].r=n-q;
	}
	sort(a+1,a+num+1,cmp);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].l!=a[i-1].l||a[i].r!=a[i-1].r)
		{
			s[++cur].l=a[i].l;
			s[cur].r=a[i].r;
			s[cur].num=1;
		}
		else
			s[cur].num++;
	}
	cur=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(s[cur].r>i)
			continue;
		while(s[cur].r==i)
		{
			dp[i]=max(min(s[cur].r-s[cur].l+1,s[cur].num)+dp[s[cur].l],dp[i]);
			cur++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",n-ans);
	return 0;
}
/*
4
0 2
2 0
2 2
0 2

3
0 2
2 0 
2 2
*/