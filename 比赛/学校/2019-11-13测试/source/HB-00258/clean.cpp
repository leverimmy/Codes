#include <bits/stdc++.h>
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N = 500010;
int n,m;
int tr[N<<2],lz[N<<2];
void push_up(int k){
	tr[k]=tr[ls(k)]+tr[rs(k)];
}
void push_down(int k){
	tr[ls(k)]=0;
	tr[rs(k)]=0;
	lz[ls(k)]=1;
	lz[rs(k)]=1;
	lz[k]=0;
}
void build(int k,int l,int r){
	if(l==r){
		tr[k]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(k), l, mid);
	build(rs(k), mid+1, r);
	push_up(k);
}
void update(int k,int l,int r,int L,int R){
	if(L<=l && r<=R){
		lz[k]=1;
		tr[k]=0;
		return;
	}
	if(lz[k]){
		push_down(k);
	}
	int mid=(l+r)>>1;
	if(L<=mid){
		update(ls(k), l, mid, L, R);
	}
	if(R>mid){
		update(rs(k), mid+1, r, L, R);
	}
	push_up(k);
}
int main(){
	freopen("clean.in", "r", stdin);
	freopen("clean.out", "w", stdout);
	scanf("%d%d",&n,&m);
	build(1, 1, n);
	for(int i=1; i<=m; i++){
		int l,r;
		scanf("%d%d",&l,&r);
		update(1, 1, n, l, r);
	}
	printf("%d\n",tr[1]);
	return 0;
}

