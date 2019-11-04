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

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct node {
	int h, id;
} p[N];

template <typename T> stack {
	private:
		static const int MAX_SIZE = 2e5;
		int _top;
		T a[MAX_SIZE + 10];
	public:
		void push(T val){ a[++_top] = val;}
		void pop(){ --_top;}
		T top(){ return a[_top];}
		bool empty(){ return !_top;}
		int size(){ return }
		void clear(){ _top = 0;}
		stack(){ clear();}
};

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		p[i].h = read();
		p[i].e = read();
	}
	for(rgi i = 1; i <= n; ++i) {
		
	}
	return 0;
}

