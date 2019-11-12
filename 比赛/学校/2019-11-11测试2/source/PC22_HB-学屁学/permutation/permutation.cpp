#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=100005;
int n,a[maxn],indx,book[maxn],per[maxn];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
		cin>>a[i];
	for(rgi i=1;i<=n;++i)
	{
		++book[a[i]];
		if(book[a[i]]>indx)
			++indx;
		per[i]=book[a[i]];
	}
	for(rgi i=2;i<=n;++i)
		if(book[i]>book[i-1])
		{
			cout<<"-1"<<endl;
			return 0;
		}
	cout<<indx<<endl;
	for(rgi i=1;i<=n;++i)
		cout<<per[i]<<" ";
	cout<<endl;
	return 0;
}

