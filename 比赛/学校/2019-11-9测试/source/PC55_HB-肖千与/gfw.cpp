#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=2e5+5;
int n,ans=0;
int a[N],b[N];
int pre[N],nxt[N];
int mx[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void update(int rt,int l,int r,int p,int c){
	if(l==r) {
		mx[rt]=max(mx[rt],c);
		return ;
	}
	int mid=(l+r)>>1;
	if(p<=mid) update(ls,l,mid,p,c);
	else update(rs,mid+1,r,p,c);
	mx[rt]=max(mx[ls],mx[rs]);
}
inline int query(int rt,int l,int r,int L,int R){
	if(L>R) return 0;
	if(L<=l&&r<=R) return mx[rt];
	int mid=(l+r)>>1,res=0;
	if(L<=mid) res=max(res,query(ls,l,mid,L,R));
	if(R>mid) res=max(res,query(rs,mid+1,r,L,R));
	return res;
}
int main(){
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(int i=1;i<=n;i++) {
		if(a[i]>a[i-1]) pre[i]=pre[i-1]+1;
		else pre[i]=1;
		ans=max(ans,pre[i]);
	}
	for(int i=n;i>=1;i--) {
		if(a[i]<a[i+1]) nxt[i]=nxt[i+1]+1;
		else nxt[i]=1;
		ans=max(ans,pre[i]+query(1,1,n,a[i]+1,n));
		update(1,1,n,a[i],nxt[i]);
	}

	printf("%d",ans);
	return 0;
}
/*
9
5 3 4 9 2 8 6 7 1
*/
