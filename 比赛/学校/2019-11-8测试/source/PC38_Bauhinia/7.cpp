#include <bits/stdc++.h>
#define rgi register int
using namespace std;
int n;
bool a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	cin>>n;
	for(rgi i=2;i<=n;++i)
		if(!a[i])
		{
			for(rgi j=2;i*j<=n;++j)
				a[i*j]=1;
		}
	for(rgi i=2;i<=n;++i)
		if(!a[i])
			cout<<i<<" ";
	cout<<endl;
	return 0;
}

