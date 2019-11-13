#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;
const int M = 1e6 + 10;

ll n, m, a[N], s[N], f[N];

struct QUERY {
	ll l, r;
} q[M];

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 2e6;
		int siz;
		T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
					std::swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			std::swap(_h[1], _h[siz--]);
			int cur = 1;
			while(cur << 1 <= siz) {
				int lc = cur << 1, rc = cur << 1 | 1, nxt;
				if(rc <= siz) {
					if(_h[lc] < _h[rc])
						nxt = lc;
					else
						nxt = rc;
				}
				else
					nxt = lc;
				if(_h[nxt] < _h[cur])
					std::swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {return _h[1];}
		void clear() {siz = 0;}
		bool empty() {return !siz;}
		heap() {clear();}
};

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

heap <ll> h, del;
std::vector <ll> st[M], ed[M];

int main() {
//	freopen("shopping.in", "r", stdin);
//	freopen("shopping.out", "w", stdout);
	n = read(), m = read();
	for(rgl i = 1; i <= n; ++i)	a[i] = read(), s[i] = s[i - 1] + a[i];
	for(rgl i = 1; i <= m; ++i) {
		ll l = read(), r = read();
		if(l > r)	std::swap(l, r);
		st[l].push_back(l), ed[r + 1].push_back(l);
	}
	
	for(rgl i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
#define VEC std::vector <ll>::iterator
		for(VEC it = st[i].begin(); it != st[i].end(); ++it)	h.push(*it);
		for(VEC it = ed[i].begin(); it != ed[i].end(); ++it)	del.push(*it);
		while(!h.empty() && !del.empty() && h.top() == del.top())	h.pop(), del.pop();
		if(h.empty())	continue;
		for(rgl j = h.top(); j <= i; ++j)
			f[i] = std::max(f[i], f[j - 1] + (s[i] - s[j - 1]) * (s[i] - s[j - 1]));
	}
	
	printf("%lld", f[n]);
	
	return 0;
}
/*
14 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1
4 9
2 12

101658211991492
*/
