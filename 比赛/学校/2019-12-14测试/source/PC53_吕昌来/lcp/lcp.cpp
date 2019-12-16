#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
char a[100005];
int i,j,k;
int r,l;
int cmp (int x,int y)
{
	k=max(x,y);
	for (j=0;j<=n-k;j++)
	{
		if (a[x+j]<a[y+j])
		    return 0;
		if (a[x+j]>a[y+j])
		    return 1;
	}
	return 1;
}
int main ()
{
    freopen ("lcp.in","r",stdin);
	freopen ("lcp.out","w",stdout);
	scanf ("%d%d",&n,&m);
	cin>>a;
	for (i=1;i<=m;i++)
	{
		scanf ("%d%d",&r,&l);
		cout<<cmp(r,l)<<endl;
	}
	return 0;
}
