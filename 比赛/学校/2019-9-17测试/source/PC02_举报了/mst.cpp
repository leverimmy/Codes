#include <bits/stdc++.h>
#define maxn 100005
const double eps=1e-7;
int n,m,u[maxn],v[maxn],a[maxn],b[maxn],rank[maxn];
double w[maxn];

int cmp(int a,int b){return w[a]<w[b];}

namespace dsu {
	int fa[maxn];
	void reset(){std::memset(fa,0,sizeof(fa));}
	int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
	int check(int x,int y){return getf(x)==getf(y);}
	void merge(int x,int y){fa[getf(x)]=getf(y);}
}

int check(double x){
	dsu::reset();
	for (int i=1;i<=m;++i)w[i]=(double)a[i]-x*b[i];
	std::sort(rank+1,rank+m+1,cmp);
	int cnt=0;
	double ans=0;
	for (int i=1;i<=m;++i){
		int j=rank[i];
		if (!dsu::check(u[j],v[j])){
			ans+=w[j];
			dsu::merge(u[j],v[j]);
			cnt++;
		}
	}if (cnt<n-1)return 0;
	return ans<=0;
}

int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d%d",&u[i],&v[i],&a[i],&b[i]);
		rank[i]=i;
	}double l=0,r=2147483647;
	while (r-l>eps){
		double mid=l+(r-l)/2;
		if (check(mid))r=mid;
		else l=mid;
	}printf("%.5f",l+(r-l)/2);
	return 0;
}
