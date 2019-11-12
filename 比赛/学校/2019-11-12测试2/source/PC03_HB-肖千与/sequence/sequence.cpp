#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5; 
int n,m;ll k;
int a[N],c[N];
ll sum[N],b[N],mn=0;
inline void add(int x,int y){
	for(;x<=n+1;x+=x&-x) c[x]+=y;
}
inline int query(int x){
	int res=0;
	for(;x;x-=x&-x) res+=c[x];
	return res; 
}
inline int get_id(ll x){
	return upper_bound(b+1,b+m+1,x)-b-1;
}

inline bool check(ll x){
	ll res=0;
	memset(c,0,sizeof(c));
	add(get_id(0),1);
	for(int i=1;i<=n;i++){
		int t=get_id(sum[i]-x);
		res+=query(t);
		add(get_id(sum[i]),1);
	}
	return res>=k;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i],b[i]=sum[i],mn=min(mn,sum[i]);
	b[n+1]=0;m=n+1;
	sort(b+1,b+m+1);m=unique(b+1,b+m+1)-b-1;
	ll l=-1e11,r=1e11,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
