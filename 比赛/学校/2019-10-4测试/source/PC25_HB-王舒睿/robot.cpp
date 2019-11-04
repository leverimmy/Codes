#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int i[50001];
	int n,m1,m2;
	int h[50001];
	int a,b;
	cin>>n>>m1>>m2;
	for(a=1;a<=n;a++)
	{
		cin>>h[a];
		i[a]=1;
	}
	for(a=1;a<=n;a++)
	{
		for(b=1;b<a;b++)
		{
			if(h[b]<=h[a])
				i[a]=max(i[a],i[b]+1);
		}
	}
	int ans=n-i[n];
	for(a=1;a<=n;a++)
			i[a]=1;
	for(a=1;a<=n;a++)
	{
		for(b=1;b<a;b++)
		{
			if(h[b]>=h[a])
				i[a]=max(i[a],i[b]+1);
		}
	}
	ans=min(ans,n-i[n]);
	cout<<m1*ans;
	return 0;
}
