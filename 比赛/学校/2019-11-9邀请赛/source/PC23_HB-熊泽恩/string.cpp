#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;

int n, len, L, max_len, cnt;
char A[N];

template <typename T> class stack {
	private:
		static const int MAX_SIZE = 1e6;
		int _top; T _s[MAX_SIZE + 10];
	public:
		void push(T val) {_s[++_top] = val;}
		void pop() {--_top;}
		T top() {return _s[_top];}
		bool empty() {return !_top;}
		void clear() {_top = 0;}
		stack() {clear();}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

stack <char> stk;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	
	scanf("%s", A + 1);
	len = strlen(A + 1);
	
	for(rgi i = 1; i <= len; ++i) {
		if(A[i] == '(') {
			stk.push('(');
			L++;
		}
		if(A[i] == ')') {
			if(stk.top() == '(') {
				stk.pop();
				L++;
			}
			else {
				stk.clear();
				L = 0;
			}
		}
		if(stk.empty())
			max_len = std::max(max_len, L);
	}
	
	stk.clear(), L = 0;
	
	for(rgi i = 1; i <= len; ++i) {
		if(A[i] == '(') {
			stk.push('(');
			L++;
		}
		if(A[i] == ')') {
			if(stk.top() == '(') {
				stk.pop();
				L++;
			}
			else {
				stk.clear();
				L = 0;
			}
		}
		if(stk.empty())
			cnt += L == max_len;
	}
	
	printf("%d %d", max_len, cnt);
	
	return 0;
}

