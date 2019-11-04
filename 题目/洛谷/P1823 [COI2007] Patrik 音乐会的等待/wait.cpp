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

int n; ll ans;

struct node {
	int h, cnt;
	bool operator <= (const struct node & rhs) const {
		return h <= rhs.h;
	}
} p[N];

template<typename T> class stack{
	private:
		static const int MAX_SIZE = 5e5;
	public:
		int _top;
		T a[MAX_SIZE + 10];
		void push(T val){ a[++_top] = val;}
		void pop(){ _top--;}
		bool empty(){ return !_top;}
		T top(){ return a[_top];}
		void clear(){ _top = 0;}
		bool size(){ return _top;}
		stack(){ clear();}
};

stack <struct node> stk;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("testdata (1).in", "r", stdin);
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		p[i].h = read();
		p[i].cnt = 1; 
	}
	for(rgi i = 1; i <= n; ++i) {
		while(stk.top() <= p[i] && !stk.empty()) {
			ans += stk.top().cnt;
			if(stk.top().h == p[i].h)
				p[i].cnt += stk.top().cnt;
			stk.pop();
		}
		
		ans += !stk.empty();
		stk.push(p[i]);
	}
	printf("%lld", ans);
	return 0;
}
/*
7 
2 
4 
1 
2 
2 
5 
1

*/
