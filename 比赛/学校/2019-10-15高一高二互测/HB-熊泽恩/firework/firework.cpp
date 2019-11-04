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

struct firework {
	ll p, t;
	bool operator < (const struct firework &rhs) const {
		if(t == rhs.t)	return p < rhs.p;
		return t > rhs.t;
	}
} f[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 1e5;
		int siz; T _h[MAX_SIZE + 10];
	public:
		void clear() {
			siz = 0; 
		}
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
					swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			swap(_h[1], _h[siz--]);
			int cur = 1;
			while((cur << 1) <= siz) {
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
					swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {
			return _h[1];
		}
		int size() {
			return siz;
		}
		bool empty() {
			return siz == 0;
		} 
		heap() {
			clear();
		}
};

int main() {
//	freopen("firework.in", "r", stdin);
//	freopen("firework.out", "w", stdout);
	n = read(), L = read();
	
	for(rgi i = 1; i <= n; ++i) {
		f[i].t = read(), f[i].p = read();
		ans += f[i].p;
	}
		
	sort(f + 1, f + n + 1);
	
	heap <int> q;
	
	for(rgi i = 1; i <= n; ++i) {
		
		q.push(f[i].p);
		q.push(f[i].p);
		
		ans -= q.top();
		q.pop();
	}
	
	printf("%lld", ans);
	return 0;
}
/*
4 5
1 3
1 4
3 3
4 4

2384
*/
