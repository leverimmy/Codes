#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[1005][1005];
int main()
{
	freopen ("run.in","r",stdin);
	freopen ("run.out","w",stdout);
	int i,j,k,l;
	int n,m;
	scanf ("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		cin>>j>>k>>l;
		a[j][k]=a[k][j]=l;
	}
	for (k=1;k<=n;k++)
	    for (i=1;i<=n;i++)
	        for (j=1;j<=n;j++)
	            a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
    int p;
	cin>>p;
	for (i=1;i<=p;i++)
	{
		cin>>j>>k;
		cout<<a[j][k]<<endl;
	}
	return 0;
}
