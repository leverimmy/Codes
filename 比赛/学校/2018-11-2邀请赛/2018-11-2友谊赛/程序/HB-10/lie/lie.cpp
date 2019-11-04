#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100005

int n, t1, t2, tail=0, tail2=0;
struct sin {
	int l, r, v;
}greed[100005], pride[100005];
int cmp1(sin a, sin b) {
	if (a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}int cmp2(sin a, sin b) {
	return a.r<b.r;
}int wrath[100005]={0};

int apocalypse(int p) {
	int l=1, r=p, ans=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (pride[mid].r<pride[p].l) {ans=mid; l=mid+1;}
		else r=mid-1;
	}return ans;
}
int main() {
	freopen("lie.in", "r", stdin);
	freopen("lie.out", "w", stdout);
	int ans=0, cnt=0;
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d", &t1, &t2);
		greed[++tail].l=t1+1; greed[tail].r=n-t2;
		if (greed[tail].l>greed[tail].r) tail--;
	}std::sort(greed+1, greed+tail+1, cmp1);
	pride[0].r=0;
	for (int i=1;i<=tail;++i) {
		if (greed[i].l!=pride[tail2].l||greed[i].r!=pride[tail2].r) {
			pride[tail2].v=std::min(pride[tail2].r-pride[tail2].l, cnt)+1; cnt=0;
			pride[++tail2].l=greed[i].l; pride[tail2].r=greed[i].r; 
		}else cnt++;
	}pride[tail2].v=std::min(pride[tail2].r-pride[tail2].l, cnt)+1;
	std::sort(pride+1, pride+tail2+1, cmp2);
	std::memset(wrath, 0, sizeof(wrath));
	for (int i=1;i<=tail2;++i) {
		wrath[i]=std::max(wrath[i-1], wrath[apocalypse(i)]+pride[i].v);
	}printf("%d", n-wrath[tail2]);
	return 0;
}
