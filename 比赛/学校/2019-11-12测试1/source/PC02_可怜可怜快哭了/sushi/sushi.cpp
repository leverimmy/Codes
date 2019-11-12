#include <bits/stdc++.h>
#define ll long long

char s[1000005];
int n,cnt[1000005];
ll sum[1000005];
int tor(int x){
	x++;if (x>n)x=1;
	return x;
}
int conv(int x){
	while (x>n)x-=n;
	return x;
}

ll qsum(int l,int r){return sum[r]-sum[l-1];}
ll qcnt(int l,int r){return cnt[r]-cnt[l-1];}
ll det(int x){return (ll)x*(x+1)/2;}

ll queryl(int s,int t){
	if (s<=t){return qsum(s,t)-qcnt(s,t)*s+qcnt(s,t)-det(qcnt(s,t));}
	else {
		ll ans=qsum(s,n)-qcnt(s,n)*s+qcnt(s,n);
		ans+=qsum(1,t)+qcnt(1,t)*(n-s)+qcnt(1,t);
		return ans-det(qcnt(s,n)+qcnt(1,t));
	}
}

ll queryr(int s,int t){
	if (s<=t){return qcnt(s,t)*t-qsum(s,t)+qcnt(s,t)-det(qcnt(s,t));}
	else {
		ll ans=qcnt(s,n)*n-qsum(s,n)+qcnt(s,n)*t+qcnt(s,n);
		ans+=qcnt(1,t)*t-qsum(1,t)+qcnt(1,t);
		return ans-det(qcnt(s,n)+qcnt(1,t));
	}
}

int mid(int l,int r){
	if (l<=r)return (l+r)>>1;
	else return conv((l+r+n)>>1);
}

void solve(){
	scanf("%s",s+1);
	n=std::strlen(s+1);
	int p1=0,cnt1=0;ll ans=(ll)1<<(ll)60;
	for(int i=1;i<=n;++i)if (s[i]==s[1]){p1=i;cnt1++;}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1],cnt[i]=cnt[i-1];
		if (s[i]!=s[1]){sum[i]+=i;cnt[i]+=1;}
	}if (cnt1==1){printf("0\n");return ;}
	for(int p=1;p<=n;++p){
		if (s[p]!=s[1])continue;
	//	printf("%d - (%d) - %d = %d + %d\n",p,mid(p,p1),p1,queryl(p,mid(p,p1)),queryr(mid(p,p1)+1,p1));
		ans=std::min(ans,queryl(p,mid(p,p1))+queryr(mid(p,p1)+1,p1));
		p1=tor(p1);while (s[p1]!=s[1])p1=tor(p1);
	}printf("%lld\n",ans);
}

int main(){
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	int t;scanf("%d",&t);while(t--)solve();return 0;
}
