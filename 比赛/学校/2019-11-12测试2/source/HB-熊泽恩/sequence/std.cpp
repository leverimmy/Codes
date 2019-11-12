#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
int n,a[maxn],tl;
ll k,sum[maxn],h[maxn];

struct Fenwick_Tree {
	int sum[maxn];
	void add(int x,int v){
	//	printf("+%d\n",x);
		while (x<=n){sum[x]+=v;x+=x&-x;}
	}int query(int x){
	//	printf("q %d\n",x);
		int ans=0;
		while (x>=1){ans+=sum[x];x-=x&-x;}
		return ans;
	}
}BIT;

int check(ll x){
//	printf("checking %lld\n",x);
	ll ans=0;
	std::memset(BIT.sum,0,sizeof(BIT.sum));
	BIT.add(std::lower_bound(h+1,h+tl+1,(ll)0)-(h+1)+1,1);
	for(int i=1;i<=n;++i){
		int d=std::upper_bound(h+1,h+tl+1,sum[i]-x)-(h+1);
		ans+=BIT.query(d);
		BIT.add(std::lower_bound(h+1,h+tl+1,sum[i])-(h+1)+1,1);
	}//printf("%lld\n",ans);
	return ans>=k;
}

int main(){
	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%d%lld",&n,&k);h[1]=sum[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		h[i+1]=sum[i];
	}std::sort(h+1,h+n+2);tl=std::unique(h+1,h+n+2)-(h+1);
	ll l=-(ll)1<<(ll)60,r=(ll)1<<(ll)60,ans=0;
	while (l<=r){
		ll mid=(l+r)>>1;
		if (check(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}std::cout<<ans;
	return 0;
}
