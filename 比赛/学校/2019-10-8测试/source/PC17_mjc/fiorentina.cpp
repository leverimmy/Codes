#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,p;
int f[100010];
int a[100010];
signed main(){
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=p;j>=i;j--){
			if(f[j-i]){
				f[j]=(f[j]+f[j-i])%mod;
			}	
		}
	}	
	printf("%lld\n",f[p]%mod);
}
