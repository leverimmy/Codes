#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define maxm 1000005
int n,m,a[5005],l[1000005],r[1000005],minl[5005]={0};
std::vector<int>inc[5005],dec[5005];
ll f[5005];
ll sqr(int x){return (ll)x*x;}

struct segmentTree {
	int min[maxm<<2],ref[maxm];
	void reset(){std::memset(min,63,sizeof(min));}
	void build(int l,int r,int rt){
		if (l==r){ref[l]=rt;return;}
		build(l,(l+r)>>1,rt<<1);build(((l+r)>>1)+1,r,rt<<1|1);
	}void modify(int p,int v){
		int rt=ref[p];min[rt]=v;rt>>=1;
		while (rt){min[rt]=std::min(min[rt<<1],min[rt<<1|1]);rt>>=1;}
	}
}sgt;

inline int read(){
	int x=0,c=getchar();
	while (c<'0'||c>'9')c=getchar();
	while ('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x;
}

int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		a[i]=read();a[i]+=a[i-1];
	}
	for(int i=1;i<=m;++i){
		l[i]=read();r[i]=read();
		inc[l[i]].push_back(i);
		dec[r[i]].push_back(i);
	}sgt.reset();sgt.build(1,m,1);
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(register int j=0;j<inc[i].size();++j)sgt.modify(inc[i][j],l[inc[i][j]]);
		f[i]=f[i-1];
		for(register int j=sgt.min[1];j<=i;++j)f[i]=std::max(f[i],f[j-1]+sqr(a[i]-a[j-1]));
		for(register int j=0;j<dec[i].size();++j)sgt.modify(dec[i][j],1e9);
	}printf("%lld",f[n]);
	return 0;
}
