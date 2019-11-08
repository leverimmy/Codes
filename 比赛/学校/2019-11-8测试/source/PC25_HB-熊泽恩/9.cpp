#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int Q;

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 2e5;
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
		T top() {
			return _h[1];
		}
		void clear() {
			siz = 0;
		}
		bool empty() {
			return !siz;
		}
		heap() {
			clear();
		}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

heap <int> q;

int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	Q = read();
	while(Q--) {
		int op = read();
		if(op == 1) {
			int val = read();
			q.push(-val);
		}
		else if(op == 2) {
			if(q.empty())
				puts("-1");
			else {
				printf("%d\n", -q.top());
				q.pop();
			}
		}
	}
	return 0;
}
/*
5
1 1
1 2
2
1 2
2

*/
