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
const int N=1e5+1;
int n,m,p,k,cnt;
int a[N];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>a[i];
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>p>>k;
		cnt=0;
		while(p<=n)
		{
			p=p+a[p]+k;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
