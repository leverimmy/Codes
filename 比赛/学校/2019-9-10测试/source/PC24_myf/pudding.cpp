#include <iostream>
#include <cstdio>
#define rgi register int
using namespace std;
int n,m,a[100005];
inline void change(int p,int q)
{
	if(p==q)
		return;
	for(rgi i=1;i<=n;++i)
		if(a[i]==p)
			a[i]=q;
}
inline int check()
{
	int ans=n;
	for(rgi i=1;i<=n;++i)
		if(a[i]==a[i-1])
			--ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	cin>>n>>m;
	for(rgi i=1;i<=n;++i)
		cin>>a[i];
	a[0]=a[n+1]=2147483647;
	while(m--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int p,q;
			cin>>p>>q;
			change(p,q);
		}
		else
			cout<<check()<<endl;
	}
	return 0;
}
