#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
long long a[5];
int cnt;
void dfs()
{
	a[3]=max(a[1],a[2])%min(a[1],a[2]);
	a[4]=min(a[1],a[2])-a[3];
	if(a[3]==0)
	{
		cnt++;
		return;
	}
	if(a[4]==0)
	{
		cnt+=2;
		return;
	}
	cnt+=1+max(a[3],a[4])/min(a[3],a[4]);
	a[1]=a[3];
	a[2]=a[4];
	dfs();
	return;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a[1]>>a[2];
	cnt+=1+max(a[1],a[2])/min(a[1],a[2]);
	dfs();
	if(a[1]==a[2])
	{
		cnt--;
	}
	cout<<cnt-1;
	return 0;
}
