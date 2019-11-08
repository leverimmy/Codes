#include <bits/stdc++.h>
#define rgi register int
using namespace std;
int n,a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(rgi i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

