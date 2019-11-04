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
const int N = 5e5 + 10;

int n, T;

struct station {
	int dis, val;
} a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 2e5;
		int siz, _h[MAX_SIZE];
	public:
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
		T top() {return _h[1];}
		bool empty() {return siz;}
		int size() {return siz;}
		void clear() {siz = 0;}
		heap() {clear();}
};

int main() {
	n = read(), T = read();
	for(rgi i = 1; i <= n; ++i) {
		a[i].dis = a[i - 1].dis + read();
		a[i - 1].val = read();
	}
	
	return 0;
}
/*
3 15
10 2
9 1
8 3

*/
