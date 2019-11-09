#include <bits/stdc++.h>
#define maxn 200005
int n,a[maxn],pre[maxn],suff[maxn],h[maxn];

struct segmentTree {
	int max[maxn<<2];
	void modify(int p,int l,int r,int v,int rt){
		if(l==r){max[rt]=std::max(max[rt],v);return;}
		int mid=(l+r)>>1;
		if (p<=mid)modify(p,l,mid,v,rt<<1);
		else modify(p,mid+1,r,v,rt<<1|1);
		max[rt]=std::max(max[rt<<1],max[rt<<1|1]);
	}int query(int l,int r,int L,int R,int rt){
		if (l>R||r<L)return 0;
		if (l<=L&&R<=r)return max[rt];
		return std::max(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
	}
}sgt;

int main(){
	freopen("gfw.in","r",stdin); 
	freopen("gfw.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);h[i]=a[i];}
	std::sort(h+1,h+n+1);int tl=std::unique(h+1,h+n+1)-(h+1);
//	printf("%d ",tl); 
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(h+1,h+tl+1,a[i])-(h+1)+1;
//	for(int i=1;i<=n;++i)printf("%d ",a[i]);printf("\n");
	pre[1]=1;
	for(int i=2;i<=n;++i){
		pre[i]=1;
		if (a[i]>a[i-1])pre[i]=pre[i-1]+1;
	}suff[n]=1;
	for(int i=n-1;i>=1;i--){
		suff[i]=1;
		if (a[i]<a[i+1])suff[i]=suff[i+1]+1;
	}std::memset(sgt.max,0,sizeof(sgt.max));
	int ans=0;
	for(int i=n;i>=1;i--){
		ans=std::max(ans,pre[i]+sgt.query(a[i]+1,n,1,n,1));
		sgt.modify(a[i],1,n,suff[i],1);
	}printf("%d",ans);
	return 0;
}
