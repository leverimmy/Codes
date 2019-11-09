#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int r2[1000010];
int r1[1000010];
int m[1000010];
int n;
int b[1000010];
map<int,int > p;
int to[1000010];
const int maxn=200010;
struct tree{
	int l,r;
	int add,pre;
}t[maxn*4];
void pushup(int p){
	t[p].pre=(t[p*2].pre+t[p*2+1].pre);
}
void pushdown(int p){
	if(t[p].add){
		t[p*2].add+=t[p].add;
		t[p*2+1].add+=t[p].add;
		t[p*2].pre+=(t[p*2].r-t[p*2].l+1)*t[p].add;
		t[p*2+1].pre+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].add;
		t[p].add=0;
	}
}
void build(int p,int l,int r){
	t[p].l=l;t[p].r=r;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
void update(int p,int x,int y,int z){
	if(t[p].l>=x && t[p].r<=y){
		t[p].add+=z;
		t[p].pre+=z*(t[p].r-t[p].l+1); 
		return;
	}
	int mid=(t[p].l+t[p].r)>>1;
	pushdown(p);
	if(x<=mid) update(p*2,x,y,z);
	if(y>mid)  update(p*2+1,x,y,z);
	pushup(p);
}
int query(int p,int x,int y){
	if(t[p].l>=x && t[p].r<=y){
		return t[p].pre;
	}
	int mid=(t[p].l+t[p].r)>>1;
	int ans=0;
	pushdown(p);
	if(x<=mid) ans=max(query(p*2,x,y),ans);
	if(y>mid)  ans=max(query(p*2+1,x,y),ans);	
	return ans;
}
int cnt=0;
int f[2000010];
int main(){
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(!p[b[i]]){
			p[b[i]]=++cnt;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=p[a[i]];
	}
	r2[n]=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]){
			r2[i]=r2[i+1]+1;
		}
		else{
			r2[i]=1;
		}
	}
	r1[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			r1[i]=r1[i-1]+1;
		}
		else{
			r1[i]=1;
		}
	}
	int ans=0;
//	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>a[i]){
					f[i]=max(f[i],r2[j]);	
				}
			}
			f[i]+=r1[i];
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
//	else{
//		build(1,1,n);
//		for(int i=1;i<=n;i++){
//			int a1=query(1,1,a[i]-1);
//			ans=max(ans,a1+r2[i]);
//			update(1,a[i],a[i],r1[i]);
//		}
//		printf("%d\n",ans);
//	}

