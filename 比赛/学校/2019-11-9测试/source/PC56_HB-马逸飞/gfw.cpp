#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=200005;
int n,ans,a[maxn];
vector<int> t;
int doit()
{
	int num=t.size(),l=t[0],pos=0,ret=0;
	t.push_back(0);
	for(rgi i=1;i<=num;++i)
		if(t[i]<=l)
		{
			ret=max(ret,i-pos);
			l=t[i],pos=i;
		}
		else
			l=t[i];
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	/*
	for(rgi i=1;i<=6;++i)
	{
		int x;
		cin>>x;
		t.push_back(x);
	}
	cout<<doit()<<endl;*/
	cin>>n;
	for(rgi i=1;i<=n;++i)
		cin>>a[i];
	for(rgi i=1;i<=n;++i)
		for(rgi j=i;j<=n;++j)
		{
			t.clear();
			for(rgi k=1;k<i;++k)
				t.push_back(a[k]);
			for(rgi k=j+1;k<=n;++k)
				t.push_back(a[k]);
			ans=max(ans,doit());
		}
	t.clear();
	for(rgi i=1;i<=n;++i)
		t.push_back(a[i]);
	ans=max(ans,doit());
	cout<<ans<<endl;
	return 0;
}
