#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=1000000000000ll;
const double eps=1e-6;
vector<int>v;
set<int>rem,v2;
void get(int x,int val)
{
	if(x==13) return;
	if(val&&val<=1000000) v.push_back(val);
	else if(val) v2.insert(val);
	get(x+1,val*10+4);
	get(x+1,val*10+7);
}
map<pair<int,int>,bool>mp;
void dfs(int x,int val)
{
	if(x==v.size())
		return;
	if(val>1000000)
	{
		v2.insert(val);
		return;
	}
	else
	rem.insert(val);
	dfs(x+1,val);
	for(int i=1;val*v[x]<=mx;i++)
	{
		val*=v[x];
		dfs(x+1,val);
	}
}
#define IT set<int>::iterator
bool check(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)
			return false;
		x/=10;
	}
	return true;
}
vector<int>storage1,storage2;
int get(int x)
{
	int ans=0;
	for(IT it1=rem.begin();it1!=rem.end();it1++)
	{
		int mx=x/(*it1);
		ans+=upper_bound(storage1.begin(),storage1.end(),mx)-storage1.begin();
		ans+=upper_bound(storage2.begin(),storage2.end(),mx)-storage2.begin();
	}
	return ans;
}
signed main()
{
	freopen("prd.in","r",stdin);
	freopen("prd.out","w",stdout);
	get(1,0);
	dfs(0,1);
	rem.erase(1);
	for(IT it1=rem.begin();it1!=rem.end();it1++)
		storage1.push_back(*it1);
	storage2.push_back(0);
	for(IT it1=v2.begin();it1!=v2.end();it1++)
		storage2.push_back(*it1);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",get(r)-get(l-1));
	}
	return 0;
} 
