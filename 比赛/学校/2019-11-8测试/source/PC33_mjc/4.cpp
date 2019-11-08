#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[1000100];

signed main(){
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
}
