#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;

int T, n, q[N], p[N], book[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct deque {
	int _head, _tail;
	int _q[N];
	void push_back(int val) {
		_q[++_tail] = val;
	}
	void pop_front() {
		++_head;
	}
	int front() {
		return _q[_head + 1];
	}
} que;

int main() {
	T = read();
	while(T--) {
		n = read(); que._head = que._tail = 0;
		int flag = 0;
		for(rgi i = 1; i <= n; ++i) q[i] = read(), que.push_back(i);
		for(rgi i = 1; i <= n; ++i) book[i] = 0;
		for(rgi i = 1; i <= n; ++i) {
			
//			int cur = *std::lower_bound(s.begin(), s.end(), q[i]);
			int cur = q[i];
//			if(cur == q[i])
//				p[i] = cur, s.erase(cur);
			if(!book[cur])
				p[i] = cur, book[cur] = 1;
			else {
//				if(q[i] == q[i - 1] && *s.begin() <= q[i]) {
//					p[i] = *s.begin();
//					s.erase(*s.begin());
//				}
				while(book[que.front()]) que.pop_front();
				if(q[i] == q[i - 1] && que.front() <= q[i]) {
					p[i] = que.front();
					que.pop_front();
				}
				else {
					flag = 1;
					break;
				}
			}
		}
//		printf("ans : ");
		if(flag)
			puts("-1");
		else {
			for(rgi i = 1; i <= n; ++i) printf("%d ", p[i]);
			puts("");
		}
	}
	return 0;
}

