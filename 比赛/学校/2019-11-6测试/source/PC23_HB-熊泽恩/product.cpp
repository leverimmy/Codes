#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;

int n, tot, a[N], ans = oo, cost, tim;

struct node {
	int t, d;
} p[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template <typename T> class stack {
	private:
		static const int MAX_SIZE = 2e5;
		int _top, _s[MAX_SIZE + 10];
	public:
		void push(T val) {_s[++_top] = val;}
		void pop() {--_top;}
		T top() {return _s[_top];}
		bool empty() {return !_top;}
		void clear() {_top = 0;}
		stack() {clear();}
};

stack <int> stk;

void dfs(int x, int step) {
	
	if(cost >= ans)	return;
	
	if(step == (n << 1 | 1)) {
		int sum = 0;
		for(rgi i = 1, t = 0; i <= n; t += p[a[i]].t, ++i)
			sum += (t + p[a[i]].t) * p[a[i]].d;
		ans = std::min(ans, sum);
		return;
	}
	
	if(x <= n) {
		stk.push(x);
		dfs(x + 1, step + 1);
		stk.pop();
	}
	
	if(!stk.empty()) {
		int cur = stk.top();
		a[++tot] = cur;
		
		tim += p[cur].t;
		cost += tim * p[cur].d;
		
		stk.pop();
		dfs(x, step + 1);
		stk.push(cur);
		tot--;
		
		cost -= tim * p[cur].d;
		tim -= p[cur].t;
		
	}
	
}

int main() {
	freopen("product.in", "r", stdin);
	freopen("product.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	p[i].t = read(), p[i].d = read();
	
	dfs(1, 1);
	
	printf("%d", ans);
	return 0;
}
/*
4
1 4
3 2
5 2
2 1

*/
