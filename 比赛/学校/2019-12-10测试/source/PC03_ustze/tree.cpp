#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
typedef long long ll;
int n;
ll fac[N],deg[N];
ll ans=1;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int a,b;scanf("%d%d",&a,&b);
		deg[a]++,deg[b]++;
		ans=ans*(1ll*deg[a]*deg[b]%mod)%mod;
	}
	printf("%lld",ans*n%mod);
	return 0;
}
