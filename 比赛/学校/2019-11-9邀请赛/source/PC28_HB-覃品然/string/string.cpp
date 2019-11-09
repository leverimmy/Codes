#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[1000005];
int n,zhan[1000005],cnt,tail,len,_max=0,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
		tail++;
		cin>>a[i];
		zhan[tail]=a[i]-39;
		if(zhan[tail]==1)
		{
			cnt++;
		}
		if(zhan[tail]==2)
		{
			cnt--;
			if(cnt>=0)
			{
				len+=2;
				if(_max<len)
				{
					_max=len;
				}
			}
			if(cnt<0)
			{
				cnt=0;
				len=0;
				tail--;
			}
		}		
	}
	len=0,tail=0;
	memset(zhan,0,sizeof(zhan));
	for(int i=0;i<=n-1;i++)
	{
		tail++;
		zhan[tail]=a[i]-39;
		if(zhan[tail]==1)
		{
			cnt++;
		}
		if(zhan[tail]==2)
		{
			cnt--;
			if(cnt>=0)
			{
				len+=2;
				if(len==_max)
				{
					ans++;
				}
			}
			if(cnt<0)
			{
				cnt=0;
				len=0;
				tail--;
			}
		}		
	}
	cout<<_max<<" "<<ans;
	return 0;
}
