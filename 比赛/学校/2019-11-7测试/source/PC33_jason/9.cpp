#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

signed main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	int a,b,c;
	cin>>a;
	getchar();
	cin>>b;
	getchar();
	cin>>c;
	int las=0,tot=0;
	vector<int>v;
	for(int i=1;i<=a;i++)
		if(i%b==c)
			v.push_back(i);
	for(int i=0;i+10<v.size();i+=10)
	{
		for(int j=0;j<9;j++)
			printf("%d,",v[i+j]);
		printf("%d",v[i+9]);
		las=i+10;
		printf("\n");
	}
	for(int i=las;i<(int)v.size()-1;i++)
		printf("%d,",v[i]);
	printf("%d",v[v.size()-1]);
	return 0;
}
