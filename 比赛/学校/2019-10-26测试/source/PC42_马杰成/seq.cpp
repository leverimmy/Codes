#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
int gcd(int a,int b){
	if(b==0) return a;
	else{
		ans+=a/b;
		return gcd(b,a%b);
	}
}

int a,b;

signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	gcd(a,b);
	printf("%lld\n",ans+1);
}
