#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, k, tot;
int a[N];

struct INTERVAL {
	int l, r, val, cnt;
} bet[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int pos) {
	
	for(rgi i = 1; i <= n; ++i) {
		if(i <= bet[pos].l)
			vec.push_back(i);
		else if(i > bet[pos].r)
			vec.push_back(i);
	}
	
	for(rgi i = 0; i < vec.size()) {
		
	}
	
}

int main() {
//	freopen("zuma.in", "r", stdin);
//	freopen("zuma.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		if(i == 1 || a[i] != a[i - 1]){
			bet[++tot].l = i;
			bet[tot].r = i;
			bet[tot].cnt = 1;
			bet[tot].val = a[i];
		}
		else {
			bet[tot].cnt++;
			bet[tot].r = i;
		}
	}
	
	for(rgi i = 1; i <= tot; ++i) {
		for(rgi j = 1; j <= n; ++j)	b[j] = a[i];
		siz = n;
		if(bet[i].cnt >= k)	continue;
		else	dfs(i);
	}
	
	printf("%d", ans);
	
	return 0;
}
/*
10 4
3 3 3 3 2 3 1 1 1 3

*/
