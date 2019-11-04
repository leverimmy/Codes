#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans=1;
int main() 
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int a;
	int n,m,k;
	cin>>n>>m>>k;
	int y=min(m-1,n-k-m+1);
	for(a=n-k-y+1;a<=n-k;a++)
		ans*=a;
	int b;
	int c=1;
	for(b=1;b<=y;b++)
		c*=b;
	cout<<a/c%1000000007;
	return 0;
}
