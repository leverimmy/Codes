#include<bits/stdc++.h>
using namespace std;
int n,k; 
int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	cin>>n>>k;
	int now=k,ans=0,t=now;
	while(now>n)
	{
		t=now;
		now>>=1;
		ans++;
		if(now*2<t)
			ans++;
	}
	if(abs(n-now)>=abs(t-n))
	{
		ans--;
		ans+=abs(t-n);
		if(now*2<t)
			ans--;
	}
	else
		ans+=abs(n-now);
	cout<<ans;
	return 0;
}
