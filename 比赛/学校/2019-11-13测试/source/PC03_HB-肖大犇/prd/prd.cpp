#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=1e12;
set<ll> s,ss;
ll b[1000005];
void dfs(ll x){
	if(x>mx) return;
	s.insert(x);
	dfs(x*10+4);dfs(x*10+7);
}
int main(){
	freopen("prd.in","r",stdin);
	freopen("prd.out","w",stdout);
	dfs(4);dfs(7);
	ss=s;int cnt=0;
	while(!s.empty()){
		ll x=*s.begin();b[++cnt]=x;
		for(set<ll>::iterator it=ss.begin();it!=s.end();++it) {
			ll y=*it;
			__int128 t=(__int128)x*y;
			if(t>mx){break;}
			s.insert((ll)t);
		}
		s.erase(s.begin());
	}
	int T;scanf("%d",&T);
	while(T--){
		ll l,r;scanf("%lld%lld",&l,&r);
		printf("%lld\n",upper_bound(b+1,b+cnt+1,r)-lower_bound(b+1,b+cnt+1,l));
	}
	return 0;
}
