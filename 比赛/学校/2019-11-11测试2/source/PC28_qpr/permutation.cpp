#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005],cnt1[100005],cnt2[100005],b[100005];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	cnt1[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cnt1[a[i]]++;
		if(cnt1[a[i]]>cnt1[a[i]-1])
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<cnt1[1]<<endl;
	for(int i=1;i<=n;i++)
	{
		cnt2[b[i]]++;
		cout<<cnt2[b[i]]<<" ";
	}
	return 0;
}
