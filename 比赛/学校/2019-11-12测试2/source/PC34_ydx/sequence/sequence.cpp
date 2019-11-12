#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&-x
ll C[100010],v[100010],S[100010];
std::vector<int>vec;
int n;
ll k;
void add(ll x,int p)
{
	while(p<=n)
	{
		C[p]+=x;
		p+=lowbit(p);
	}
}
ll query(int p)
{
	ll ans(0);
	while(p)
	{
		ans+=C[p];
		p-=lowbit(p);
	}
	return ans;
}
bool check(ll x)
{
	memset(C,0,sizeof(C));
	ll res(0),u;
	int p;
	for(int i=1;i<=n;i++)
	{
		u=S[i]-x;
		p=std::lower_bound(vec.begin(),vec.end(),u)-vec.begin();
		res+=query(p)+(u>0);
		p=std::lower_bound(vec.begin(),vec.end(),S[i])-vec.begin();
		add(p+1,1);
	}
	return res>=k;
}
std::priority_queue<ll,std::vector<ll>,std::greater<ll> >q;
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		S[i]=S[i-1]+v[i];
		vec.push_back(S[i]);
	}
	if(n<=10000)
	{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				ll p=S[j]-S[i-1];
				if(q.size()<k)
					q.push(p);
				else if(p>q.top())
				{
					q.pop();
					q.push(p);
				}
			}
		return!printf("%lld\n",q.top());
	}
	std::sort(vec.begin(),vec.end());
	ll l=0,r=vec[vec.size()-1];
	for(;l<r;)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		r=mid;
	}
	return!printf("%lld\n",l);
}
