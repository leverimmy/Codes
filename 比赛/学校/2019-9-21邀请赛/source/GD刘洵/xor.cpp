#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int t,n,m,x,y,z,b,xxx;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
for(int tt=1;tt<=t;tt++)
{
	cin>>n>>m;
	b=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(x==y)
		{
			xxx++;
		}
	}	
	if(xxx%2==0&&(n-xxx)%2==0)
	{
		cout<<"NO";
	}
	else cout<<"YES";
}
}
