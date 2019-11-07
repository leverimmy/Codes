#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
int x;
bool judge(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
signed main()
{
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	cin>>x;
	++x;
	while(!judge(x))
		x++;
	printf("%lld",x);
	return 0;
}