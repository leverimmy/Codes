#include<bits/stdc++.h>
using namespace std;
int a[4000001];
void out(__int128 x)
{
	vector<int>v;
	while(x)
		v.push_back(x%10),x/=10;
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		printf("%d",v[i]);
}
signed main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n;
	scanf("%d",&n);
	__int128 pre=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=pre*a[i];
		pre+=a[i];
	}
	out(ans);
	return 0;
}
