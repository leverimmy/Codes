#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,x,y;
unsigned long long res=1;
long long mod=1e9+7,cnt;

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m>>k;
	x=n-k;
	y=m-1;
	y=min(y,x-y);
	for(int i=1;i<=y;i++)
	{
		res*=x;
		cnt+=res/mod;
		res%=mod;
		x--;
	}
	for(int i=1;i<=y;i++)
	{
		while(res%i!=0)
		{
			res+=mod;
			cnt--;
			if(cnt==0)
				break;
		}
		res/=i;
		res%=mod;
	}
	cout<<res%mod<<endl;
	return 0;
} 
