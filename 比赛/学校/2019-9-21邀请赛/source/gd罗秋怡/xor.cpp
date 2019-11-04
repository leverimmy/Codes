#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
using namespace std;
int n,x,y,m,f,t,k;
int a[100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		f=0;
		for(int i=1; i<=m; i++)
		{
	    	cin>>x>>y>>k;
	    	if(x==y&&k!=0)
	    	{f=1; break;}
	    }
		if(f) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
