#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=131;
int n,f;
int p[100010];
int base[100010];
int sum[100010];
int check(int l1,int r1,int l2,int r2){
	if((sum[r1]-sum[l1-1]*base[r1-l1+1])==(sum[r2]-sum[l2-1]*base[r2-l2+1])){
		return 1;
	}
	else return 0;
}
signed main(){
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	scanf("%lld%lld",&n,&f);
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	base[0]=1;
	for(int i=1;i<=n;i++){
		base[i]=base[i-1]*mod;
		sum[i]=sum[i-1]*mod+p[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j*2+f-1>n) break;
			if(check(i,i+j-1,i+j+f,i+j+f+j-1)==1) ans++;
		}
	}
	printf("%lld\n",ans);
}
