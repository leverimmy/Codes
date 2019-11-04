#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10; 

int n, m, tot;
int a[N], num[N], tim[N], vis[N];
int nxt[N], pos[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Discrete() {
	sort(num + 1, num + tot + 1);
	tot = unique(num + 1, num + tot + 1) - (num + 1);
	for(rgi i = 1; i <= n; ++i)
		a[i] = lower_bound(num + 1, num + tot + 1, a[i]) - num;
}

il void write(int x) {
    if(x < 0)    putchar('-'), x = -x;
    if(x > 9)    write(x / 10);
    putchar(x % 10 + 48);
}

int main() {
//	freopen("2737.in", "r", stdin);
//	freopen("2737.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		num[++tot] = a[i];
	}
	
	Discrete();
	
	/*for(rgi i = 1; i <= n; ++i) {
		pos[a[i]][++time[a[i]]] = i;
		kth[i] = time[a[i]];
	}*/
	
	/*for(rgi i = n; i >= 1; --i) {
		if(!pos[a[i]]) {
			pos[a[i]] = i;
			nxt[i] = -1;
		}
		else {
			nxt[i] = pos[a[i]];
			pos[a[i]] = i;
		}
	}*/
	
	/*for(rgi i = 1; i <= n; ++i) {
		printf("%d ", nxt[i]);
	}*/
	
	/*for(rgi i = 1; i <= m; ++i) {
		memset(vis, 0, sizeof(vis));
		int l = read(), r = read(), ans = oo;
		for(rgi j = l; j <= r; ++j) {
			if(vis[a[j]])	continue;
			vis[a[j]] = 1;
			for(rgi k = nxt[j], last = j; k <= r && ~k; k = nxt[k]) {
				ans = min(ans, k - last);
				last = k;
			}
		}
		if(ans == oo)	puts("-1");
		else	printf("%d\n", ans);
	}*/
	
	for(rgi i = 1; i <= m; ++i) {
		int l = read(), r = read(), ans = oo;
		memset(vis, 0, sizeof(vis));
		for(rgi j = l; j <= r; ++j) {
			if(!vis[a[j]])	vis[a[j]] = j;
			else {
				ans = min(ans, j - vis[a[j]]);
				vis[a[j]] = j;
			}
		}
		if(ans == oo)	write(-1);
		else	write(ans);
		putchar('\n');
	}
	
	return 0;
}
/*
5 3
1 1 2 3 2
1 5
2 4
3 5

7 3
1 1 2 3 1 2 3
1 5
2 4
3 5

*/
