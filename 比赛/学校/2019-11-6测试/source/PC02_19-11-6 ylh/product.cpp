#include <bits/stdc++.h>
#define ll long long
const ll inf=(ll)1<<(ll)60;
ll f[205][205];
int n,t[205],d[205],sumt[205],sumd[205];

ll dfs(int l,int r){
	if (l>r)return 0;
	if (f[l][r]!=-1)return f[l][r];
	f[l][r]=inf;
	for(int i=l;i<=r;++i){
		f[l][r]=std::min(f[l][r],
		dfs(l,i-1)+dfs(i+1,r)+(ll)(sumt[i-1]-sumt[l-1])*(sumd[r]-sumd[i])+(ll)d[i]*(sumt[r]-sumt[i]+sumt[i-1]-sumt[l-1]+t[i]));
	}return f[l][r];
}

int main(){
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&t[i],&d[i]);
		sumt[i]=sumt[i-1]+t[i];sumd[i]=sumd[i-1]+d[i];
	}std::memset(f,-1,sizeof(f));
	printf("%lld",dfs(1,n));
	return 0;
}
