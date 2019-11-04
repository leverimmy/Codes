#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, ans, pps;
int f[N], pre[N];

std::vector <int> vec;

struct INTERVAL {
	int l, r, id;
	bool operator < (const struct INTERVAL &rhs)	const {
		if(r == rhs.r)	return l > rhs.l;
		else	return r < rhs.r;
	}
} inv[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	n = read();
	memset(pre, -1, sizeof(pre));
	
	for(rgi i = 1; i <= n; ++i)	inv[i].l = read(), inv[i].r = read(), inv[i].id = i;
	
	std::sort(inv + 1, inv + n + 1);
	
	inv[0].r = -1;
	
	inv[0].id = -1;
	
	for(rgi i = 1; i <= n; ++i) {
		int val = 0, pos = 0;
		for(rgi j = 0; j <= i - 1; ++j) if(inv[j].r < inv[i].l) {
			if(f[j] > val) {
				val = f[j];
				pos = j;
			}
			else if(f[j] == val) {
				pos = std::min(pos, j);
			}
		}
		pre[inv[i].id] = inv[pos].id;
		f[i] = val + 1;
	}
	
	for(rgi i = 1; i <= n; ++i) {
		if(f[i] > ans) {
			ans = f[i];
			pps = inv[i].id;
		}
		else if(f[i] == ans) {
			pps = std::min(pps, inv[i].id);
		}
	}
	
	for(rgi i = pps; ~i; i = pre[i])	vec.push_back(i);
	
	std::sort(vec.begin(), vec.end());

	printf("%d\n", vec.size());
		
	for(rgi i = 0; i < vec.size(); ++i)	printf("%d ", vec[i]);
	
	return 0;
}
/*
4
4 9
9 11
13 19
10 17

5
1 3
4 5
1 6
5 6
1 5

3
1 1000
2 3
5 10

*/
