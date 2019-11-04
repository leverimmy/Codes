#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	long long int a1, a2;
	long long int b1,b2;
	long long int ans;
	cin>>a1>>a2;
	b1=max(a1,a2);
	b2=min(a1,a2);
	ans=b1/b2-1;
	b1-=ans*b2;
	ans+=b1/(b1-b2)+1;
	if(b1%(b1-b2)!=0)
		cout<<ans+2;
	else
		cout<<ans;
	return 0;
}
