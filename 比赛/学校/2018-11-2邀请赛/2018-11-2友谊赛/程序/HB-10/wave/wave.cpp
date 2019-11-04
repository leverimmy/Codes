#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50005

int n, ref[50005];
struct rect {
	int x, y, vx, vy;
}rct[50005];

int cmp1(rect a, rect b) {
	return a.x<b.x;
}

struct TheSatanicBible {
	int val[maxn<<1], max[maxn<<1], left[maxn<<1], right[maxn<<1], tag[maxn<<1];
	void update(int x) {
		val[x]=val[x<<1]+val[x<<1|1];
		max[x]=std::max(max[x<<1], max[x<<1|1]);
	}
	void build(int l, int r, int x) {
		left[x]=l; right[x]=r; tag[x]=-1;
		if (l==r) {
			val[x]=0;max[x]=0;
			return;
		}build(l, ((l+r)>>1), x<<1);
		build(((l+r)>>1)+1, r, x<<1|1);
		update(x); 
	}void pushdown(int x) {
		if (tag[x]==-1) return ;
		val[x<<1]=tag[x]*(right[x<<1]-left[x<<1]+1);
		val[x<<1|1]=tag[x]*(right[x<<1|1]-left[x<<1|1]+1);
		tag[x<<1]=tag[x]; max[x<<1]=tag[x];
		tag[x<<1|1]=tag[x];max[x<<1|1]=tag[x];
		tag[x]=-1;
	} void modify(int l, int r, int v, int x) {
		if (r<l) return;
		if (left[x]>r||right[x]<l) return;
		if (l<=left[x]&&right[x]<=r) {
			tag[x]=v; val[x]=(right[x]-left[x]+1)*v; max[x]=v;
			return;
		}pushdown(x);
		modify(l, r, v, x<<1);
		modify(l, r, v, x<<1|1);
		update(x);
	} int query(int l, int r, int x) {
		if (left[x]>r||right[x]<l) return 0;
		if (l<=left[x]&&right[x]<=r) return val[x];
		pushdown(x);
		return query(l, r, x<<1)+query(l, r, x<<1|1);
	}int find(int k, int x) {
		if (left[x]==right[x]) return left[x];
		pushdown(x);
	//	printf("finding:%d %d %d\n", k, x, max[x]);
		if (max[x<<1|1]>=k) return find(k, x<<1|1);
		else return find(k, x<<1);
	}
}xl, yl;

int hx[50005], hy[50005];

int main() {
	freopen("wave.in", "r", stdin);
	freopen("wave.out", "w",stdout);
	long long ans=0;
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d", &rct[i].x, &rct[i].y);
		hx[i]=rct[i].x; hy[i]=rct[i].y;
	}std::sort(hx+1, hx+n+1);
	std::sort(hy+1, hy+n+1);
	xl.build(1, n, 1); yl.build(1, n, 1);
	for (int i=1;i<=n;++i) {
		rct[i].vx=std::lower_bound(hx+1, hx+n+1, rct[i].x)-(hx+1)+1;
		rct[i].vy=std::lower_bound(hy+1, hy+n+1, rct[i].y)-(hy+1)+1;
	} for (int i=n;i>=1;i--) {
		ans+=rct[i].y-xl.query(rct[i].vx, rct[i].vx, 1);
		xl.modify(xl.find(rct[i].y, 1), rct[i].vx, rct[i].y, 1);
		ans+=rct[i].x-yl.query(rct[i].vy, rct[i].vy, 1);
		yl.modify(yl.find(rct[i].x, 1), rct[i].vy, rct[i].x, 1);
	}printf("%lld", ans);
	
	return 0;
}
