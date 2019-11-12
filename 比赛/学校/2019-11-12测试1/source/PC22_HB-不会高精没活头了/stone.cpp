#include <bits/stdc++.h>
#define rgi register int
#define ll __int128
#define pid pair<int,double>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
int n;
ll ans;
priority_queue<ll,vector<ll>,greater<ll> > que;
inline int ri()
{
	register int o1=0;
	register char o3=getchar();
	while(!isdigit(o3))
		o3=getchar();
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o1;
}
inline void wi(ll out)
{
	ll ou=out/10;
	if(ou)
		wi(ou);
	putchar((out-(ou<<1)-(ou<<3))^48);
}
signed main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=ri();
	for(rgi i=1;i<=n;++i)
	{
		int x=ri();
		que.push((ll)x);
	}
	while(que.size()>1)
	{
		ll x=que.top();
		que.pop();
		ll y=que.top();
		que.pop();
		ans+=x*y;
		que.push(x+y);
	}
	wi(ans);
	return 0;
}

