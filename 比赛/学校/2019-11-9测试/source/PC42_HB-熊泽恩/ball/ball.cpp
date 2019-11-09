#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 2e5 + 10;

int n;

struct BALL {
	double x, r;
};

//template <typename T> class queue {
//	public:
//		static const int MAX_SIZE = 2e5;
//		int _head, _tail;
//		T a[MAX_SIZE + 10];
//		void push(T val) {a[++_tail] = val;}
//		void pop() {_head++;}
//		T top() {return a[_head + 1];}
//		int size() {return _tail - _head;}
//		bool empty() {return _tail == _head;}
//		void clear() {_head = _tail = 0;}
//		queue() {clear();}
//};

template <typename T> class stack {
	private:
		static const int MAX_SIZE = 2e5;
		int _top;	T _s[MAX_SIZE + 10];
	public:
		void push(T val) {_s[++_top] = val;}
		void pop() {--_top;}
		T top() {return _s[_top];}
		bool empty() {return !_top;}
		void clear() {_top = 0;}
		stack() {clear();}
};

stack <struct BALL> stk;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		
		double x = read(), r = read();
		
		while(!stk.empty()) {
			r = std::min(r, (x - stk.top().x) * (x - stk.top().x) / 4.0 / stk.top().r);
			if(r >= stk.top().r)
				stk.pop();
			else
				break;
		}
		stk.push(BALL{x, r});
		
		printf("%.4f\n", r);
		
	}
	
	return 0;
}
/*
3
0 9
8 1
13 7

*/
