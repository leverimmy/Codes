#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1e5 + 10;

ll n, L, ans;
ll min_time = oo, max_time = -oo, to[N];

struct firework {
	ll p, t;
	bool operator < (const struct firework &rhs) const {return t < rhs.t;}
} f[N];

//vector <ll> t[N];

struct time {
	ll cnt, a[(int)1000];
	
	void push_back(ll val) {
		a[++cnt] = val;
	}
	void my_sort() {
		sort(a + 1, a + cnt + 1);
	}
} t[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int find(int id, int l, int r, int val) {//find the first not smaller
	int res;
	while(l <= r) {
		int mid = l + r + 1 >> 1;
		if(t[id].a[mid] >= val)
			r = mid - 1;
		else
			l = mid;
		res = mid;
	}
	return res;
}

int main() {
	freopen("firework.in", "r", stdin);
	freopen("firework.out", "w", stdout);
	n = read(), L = read();
	for(rgi i = 1; i <= n; ++i) {
		f[i].t = read(), f[i].p = read();
		t[f[i].t].push_back(f[i].p);
		
		min_time = min(min_time, f[i].t);
		max_time = max(max_time, f[i].t);
	}
	
	sort(f + 1, f + n + 1);
	
	/*cout << endl;
	for(rgi i = 1; i <= 5; ++i) {
		for(rgi j = 1; j <= t[i].cnt; ++j)
			cout << t[i].a[j] << " ";
		cout << endl;
	}*/ 
	
	for(rgi i = min_time; i <= max_time; ++i) {
		t[i].my_sort();
		int pos = find(i, 1, t[i].cnt, to[i - 1]);
		to[i] = max(to[i - 1], t[i].a[pos + t[i].cnt >> 1]);
	}
	
	for(rgi i = 1; i <= n; ++i)
		ans += llabs(f[i].p - to[f[i].t]);
	
	printf("%lld", ans);
	return 0;
}
/*
4 5
1 3
1 4
3 3
4 4

*/
