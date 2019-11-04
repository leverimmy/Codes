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
const int N = 1e5 + 10;

int n;
int a[N] = {0, 1};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

class BIT {
	private:
		static const int MAX_SIZE = 1e5;
		int c[MAX_SIZE + 10];
	public:
		void add(int x, int val) {
			for(; x <= MAX_SIZE; x += x & -x)	c[x] += val;
		}
		int query(int x) {
			int res = 0;
			for(; x; x -= x & -x)	res += c[x];
			return res;
		}
		void clear() {
			memset(c, 0, sizeof(c));
		}
		BIT() {
			clear();
		}
} t;

int main() {
	n = read();
	for(rgi i = 2; i <= n; ++i)	a[i] = read() + 1;
	for(rgi i = 1; i <= n; ++i)	t.add(i, 1);
	for(rgi i = n; i >= 1; --i) {
		int l = 1, r = n, ans;
		while(l < r) {
			int mid = l + r >> 1;
			if(t.query(mid) >= a[i])
				r = mid;
			else
				l = mid + 1;
			ans = l;
		}
		a[i] = ans, t.add(ans, -1);
	}
	for(rgi i = 1; i <= n; ++i)	printf("%d\n", a[i]);
	return 0;
}
/*
5
1
2
1
0

*/
