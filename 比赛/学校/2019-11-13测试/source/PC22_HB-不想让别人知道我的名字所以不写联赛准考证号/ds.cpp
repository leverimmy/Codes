#include <bits/stdc++.h>
#define rgi register int
#define int long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=1e8;
vector<int> p;
int ret[15],n;
int pow1[15];
void dfs(int pos,int lim)
{
	if(pos==lim+1)
	{
		int r=0;
		for(rgi i=1;i<=lim;++i)
			r+=ret[i]*pow1[i];
		p.pb(r);
		return;
	}
	ret[pos]=4;
	dfs(pos+1,lim);
	ret[pos]=7;
	dfs(pos+1,lim);
	ret[pos]=0;
}
int ans=1;
void dfs2(int pos)
{
	if(pos==n)
	{
		p.pb(ans);
		return;
	}
	int tans=ans;
	dfs2(pos+1);
	for(rgi i=1;i<=18;++i)
	{
		ans*=p[pos];
		if(ans>inf)
			break;
		dfs2(pos+1);
	}
	ans=tans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	pow1[1]=1ll;
	for(rgi i=2;i<=8;++i)
		pow1[i]=pow1[i-1]*10ll;
	p.pb(4ll),p.pb(7ll);
	for(rgi i=2;i<=8;++i)
		dfs(1,i);
	sort(p.begin(),p.end());
	n=p.size();
	dfs2(0);
	sort(p.begin(),p.end());
	vector<int>::iterator it=unique(p.begin(),p.end());
	for(vector<int>::iterator i=p.begin();i!=p.end();++i)
		cout<<*i<<",";
	return 0;
}

