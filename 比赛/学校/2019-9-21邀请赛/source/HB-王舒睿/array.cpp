#include <iostream>
#include<cstdio>
#include<cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int n,m;
int a[100001];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	int b;
	for(b=1;b<=n;b++)
		cin>>a[b];
	cin>>m;
	for(b=1;b<=m;b++)
	{
		int p,k;
		cin>>p>>k;
		cout<<(n-p)/(k+a[p])+1<<endl;
	}
	return 0;
}
