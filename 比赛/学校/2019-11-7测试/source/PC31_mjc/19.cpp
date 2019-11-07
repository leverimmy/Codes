#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,r,m;
int vis[10];
int ans[1000];
int f[1000010]; 
int a,b,c,d;
signed main(){
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=m;i++){
		f[i]=f[i-1]+f[i-2];
	}
	for(int i=n;i<=m;i++){
		if(f[i]%a!=0 && f[i]%b!=0 && f[i]%c!=0 && f[i]%d!=0){
			printf("%lld ",i);
		}
	}
}
