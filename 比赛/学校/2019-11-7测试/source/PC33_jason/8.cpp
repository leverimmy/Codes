#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long

signed main()
{
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	int a,b,c;
	cin>>a;
	getchar();
	cin>>b;
	getchar();
	cin>>c;
	for(int i=1;i<=c;i++)
		for(int j=i;j<=c;j++)
			if(i*a+j*b<=c)
				cout<<i<<','<<j<<endl;
	return 0;
}