#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1000 + 10;
const int M = 1000 + 10;

int n, m, cnt, ans;
int a[N], x[M], y[M], tmp[N], cur[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Merge_Sort(int q[], int l, int r)
{
    if(l >= r)
        return;
    int mid = l + r >> 1;
    Merge_Sort(q, l, mid), Merge_Sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
        if(q[i] < q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++], ans += mid - i + 1;
    while(i <= mid)
        tmp[k++] = q[i++];
    while(j <= r)
        tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; ++i, ++j)
        q[i] = tmp[j];
}

signed main() {
	freopen("inversion.in", "r", stdin);
	freopen("inversion.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= m; ++i)	x[i] = read(), y[i] = read();
	
	for(rgi state = 0; state < 1 << m; ++state) {
		for(rgi i = 1; i <= n; ++i)	cur[i] = a[i];
		for(rgi i = 1; i <= m; ++i)	if(state & (1 << i - 1))
			std::swap(cur[x[i]], cur[y[i]]);
		Merge_Sort(cur, 1, n);
		ans += cnt;	cnt = 0;
	}
	
	printf("%.8f", ans * 1.0 / (1 << m));
	
	return 0;
}
/*
4 3
1 3 2 4
1 2
2 3
1 4

*/
