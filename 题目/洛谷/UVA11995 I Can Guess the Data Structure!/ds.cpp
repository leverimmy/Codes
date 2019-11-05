#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

int n;

#define MAX_SIZE (int)2e5 + 10

struct stack {
	ll flag, _top, _s[MAX_SIZE];
	il void push(ll val) {_s[++_top] = val;}
	il void pop() {_top--;}
	il ll top(){return _s[_top];}
	il void clear() {_top = 0, flag = 1;}
	il bool empty() {return !_top;}
	stack() {_top = 0, flag = 1;}
} stk;

struct queue {
	ll flag, _head, _tail, _q[MAX_SIZE];
	il void push(ll val) {_q[++_tail] = val;}
	il void pop() {_head++;}
	il ll front() {return _q[_head + 1];}
	il void clear() {_head = _tail = 0, flag = 1;}
	il bool empty() {return _head == _tail;}
	queue() {_head = _tail = 0, flag = 1;}
} que;

struct greater_heap {
	ll flag, _siz, _h[MAX_SIZE];
	il void push(ll val) {
		_h[++_siz] = val;
		int cur = _siz;
		while(cur > 1) {
			if(_h[cur >> 1] < _h[cur])
				std::swap(_h[cur >> 1], _h[cur]);
			else
				break;
			cur >>= 1;
		}
	}
	il void pop() {
		std::swap(_h[1], _h[_siz--]);
		int cur = 1;
		while(cur << 1 <= _siz) {
			int lc = cur << 1, rc = cur << 1 | 1, nxt;
			if(rc <= _siz) {
				if(_h[lc] > _h[rc])
					nxt = lc;
				else
					nxt = rc;
			}
			else
				nxt = lc;
			if(_h[nxt] > _h[cur])
				std::swap(_h[nxt], _h[cur]);
			else
				break;
			cur = nxt;
		}
	}
	il ll top() {return _h[1];}
	il bool empty() {return !_siz;}
	il void clear() {_siz = 0, flag = 1;}
	greater_heap() {_siz = 0, flag = 1;}
} gth;

int main() {
//	freopen("testdata.in", "r", stdin);
	while(std::cin >> n) {
		for(rgi i = 1; i <= n; ++i) {
			ll opt, v;
			std::cin >> opt >> v;
			if(opt == 1) {
				if(stk.flag)	stk.push(v);
				if(que.flag)	que.push(v);
				if(gth.flag)	gth.push(v);
			}
			if(opt == 2) {
				if(stk.empty() || stk.top() != v)	stk.flag = 0;
				else if(stk.flag)	stk.pop();
				if(que.empty() || que.front() != v)	que.flag = 0;
				else if(que.flag)	que.pop();
				if(gth.empty() || gth.top() != v)	gth.flag = 0;
				else if(gth.flag)	gth.pop();
			}
		}
		if(stk.flag && !que.flag && !gth.flag)	puts("stack");
		else if(!stk.flag && que.flag && !gth.flag)	puts("queue");
		else if(!stk.flag && !que.flag && gth.flag)	puts("priority queue");
		else if(!stk.flag && !que.flag && !gth.flag)	puts("impossible");
		else	puts("not sure");
		stk.clear(), que.clear(), gth.clear();
	}
	return 0;
}

